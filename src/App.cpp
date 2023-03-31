#include "App.h"

App::App(int argc, char **argv) {

    assert(argc == 6 && "Wrong arguments num, try again.\n");

    baseFile.init(argv[1]);
    ratingFile.init(argv[2]);
    episodeFile.init(argv[3]);
    akasFile.init(argv[4]);

    try { maxRunTime = std::stoi(argv[5]); }
    catch(...) {
        std::cout << "Invalid maximum runtime argument\n";
        exit(-1);
    }

    assert(maxRunTime > 0 && "Invalid maximum runtime argument");
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
        if (packet.second.runTime < maxRunTime) {
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
