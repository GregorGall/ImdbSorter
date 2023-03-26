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

    baseFile.load(tvSeries, tvEpisodes);

    std::thread thr1(&RatingFile::load, std::ref(ratingFile), std::ref(tvSeries));
    std::thread thr2(&AkasFile::load, std::ref(akasFile), std::ref(tvSeries));
    std::thread thr3(&EpisodeFile::load, std::ref(episodeFile), std::ref(tvSeries), std::ref(tvEpisodes));

    thr3.join();
    thr2.join();
    thr1.join();

    std::cout << "\nLoad has been finished\n";

    std::multiset<Packet> topTen;
    for (auto &packet: tvSeries) {
        if (packet.second.runTime < maxRunTime) {
            topTen.insert(packet.second);
            if (topTen.size() > 10) { topTen.erase(topTen.begin()); }
        }
    }

    std::cout << "\nTOP TEN\n\n";
    Internal::Packet::printHeader();

    for (auto &packet: topTen) {
        std::cout << packet;
    }

    return 0;
}
