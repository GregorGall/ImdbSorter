#include "FileProcessors/EpisodeFile.h"

void EpisodeFile::init(const std::string &fileName) {
    FileProcessing::init(fileName, {"tconst", "parentTconst"});
}

void EpisodeFile::load(PackDict &tvSeries, PackDict &tvEpisodes) {

    std::printf("Episode load has been started\n");

    while (!eof()) {
        auto &words = select();

        // check and add
        if (words.size() == 2 && tvSeries.contains(words.at("parentTconst")) && tvEpisodes.contains(words.at("tconst"))) {
            Packet &packet = tvSeries[words.at("parentTconst")];
            packet.runTime += tvEpisodes[words.at("tconst")].runTime;
        }
    }
}
