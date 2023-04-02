#include "App.h"

App::App(const input_t& input) {

    baseFile.init(openFile(input.baseFilePath));
    ratingFile.init(openFile(input.ratingFilePath));
    episodeFile.init(openFile(input.episodeFilePath));
    akasFile.init(openFile(input.akasFilePath));

    try {
        runTimeEdge = std::stoi(input.runTimeEdge);
        if(runTimeEdge <= 0) throw;
    }
    catch(...) {
        std::cout << "Invalid value for runTimeEdge\n";
        exit(-1);
    }

}

std::unique_ptr<std::ifstream> App::openFile(const std::string &fileName) {
    std::unique_ptr<std::ifstream> file;
    try{ file  = std::make_unique<std::ifstream>(fileName); }
    catch(std::exception& exceptMsg) {
        std::cout << "File open error: " << fileName << std::endl;
        std::cout << exceptMsg.what() << std::endl;
        file->close();
        exit(-1);
    }

    return file;
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
