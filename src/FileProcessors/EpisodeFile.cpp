#include "FileProcessors/EpisodeFile.h"

void EpisodeFile::init(std::unique_ptr<std::ifstream> fileStream) {
    FileProcessing::init(std::move(fileStream), {id, parentId});
}

void EpisodeFile::load(PackDict &tvSeries, PackDict &tvEpisodes) {

    while (!eof()) {
        auto &words = select();
        bool valid = words.size() == colNum() && tvSeries.contains(words.at(parentId));

        // check and add
        if (valid && tvEpisodes.contains(words.at(id))) {
            packet_t &packet = tvSeries[words.at(parentId)];
            packet.runTime += tvEpisodes[words.at(id)].runTime;
        }
    }
}
