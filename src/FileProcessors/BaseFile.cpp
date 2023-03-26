#include "FileProcessors/BaseFile.h"

void BaseFile::init(const std::string &fileName) {
    FileProcessing::init(fileName, {"tconst", "titleType", "primaryTitle", "isAdult", "runtimeMinutes"});
}

void BaseFile::load(PackDict &tvSeries, PackDict &tvEpisodes) {

    std::cout << "Base load has been started\n";
    while (!eof()) {
        auto &words = select();

        bool valid = words.size() == 5 && words.at("isAdult") == "0";
        bool tvSeriesString = valid && words.at("titleType") == "tvSeries";
        bool tvEpisodesString = valid && words.at("titleType") == "tvEpisode";

        if (tvEpisodesString && words.at("runtimeMinutes") != "\\N") {
            Packet packet;
            packet.id = words.at("tconst");
            packet.runTime = std::stoi(words.at("runtimeMinutes"));

            tvEpisodes[packet.id] = packet;
            continue;
        }

        if (tvSeriesString) {
            Packet packet;
            packet.id = words.at("tconst");
            packet.titleType = words.at("titleType");
            packet.title = words.at("primaryTitle");
            packet.isAdult = words.at("isAdult");

            tvSeries[packet.id] = packet;
        }
    }
}
