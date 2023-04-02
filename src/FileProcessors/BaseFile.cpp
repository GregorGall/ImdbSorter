#include "FileProcessors/BaseFile.h"

void BaseFile::init(std::unique_ptr<std::ifstream> fileStream) {
    FileProcessing::init(std::move(fileStream), {id, type, title, adultFlag, runTime});
}

void BaseFile::load(PackDict &tvSeries, PackDict &tvEpisodes) {

    while (!eof()) {
        auto &words = select();

        bool valid = words.size() == colNum() && words.at(adultFlag) == adultFlagState;
        bool tvSeriesString = valid && words.at(type) == seriesType;
        bool tvEpisodesString = valid && words.at(type) == episodeType;

        if (tvEpisodesString && words.at(runTime) != undefined) {
            packet_t packet;
            packet.id = words.at(id);
            packet.runTime = std::stoi(words.at(runTime));

            tvEpisodes[packet.id] = packet;
            continue;
        }

        if (tvSeriesString) {
            packet_t packet {
                words.at(id),
                words.at(title),
                words.at(type),
                words.at(adultFlag) };
            tvSeries[packet.id] = packet;
        }
    }
}
