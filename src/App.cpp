#include "App.h"

App::App(const input_t& input) {

    baseFile.init(input.baseFilePath);
    ratingFile.init(input.ratingFilePath);
    episodeFile.init(input.episodeFilePath);
    akasFile.init(input.akasFilePath);

    try { runTimeEdge = std::stoi(input.runTimeEdge); }
    catch(...) {
        std::cout << "Invalid value for runTimeEdge\n";
        exit(-1);
    }

    assert(runTimeEdge > 0 && "Invalid maximum runtime argument");
}

int App::exec() {

    std::cout << "Load has been started\n";

    baseFile.load(tvSeries, tvEpisodes);

    std::thread rateThread(&RatingFile::load, std::ref(ratingFile), std::ref(tvSeries));
    std::thread akasThread(&AkasFile::load, std::ref(akasFile), std::ref(tvSeries));
    std::thread episodeThread(&EpisodeFile::load, std::ref(episodeFile), std::ref(tvSeries), std::ref(tvEpisodes));

    episodeThread.join();
    akasThread.join();
    rateThread.join();

    std::cout << "Load has been finished\n";

    std::multiset<packet_t> topTen;
    for (auto &packet: tvSeries) {
        if (packet.second.runTime < runTimeEdge) {
            topTen.insert(packet.second);
            if (topTen.size() > topNum) {
              topTen.erase(topTen.begin());
            }
        }
    }

    std::cout << "\nTOP TEN\n\n";
    Internal::packet_t::printHeader();

    for (auto &packet: topTen) {
        std::cout << packet;
    }

    return 0;
}
