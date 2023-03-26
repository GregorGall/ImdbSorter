#include "FileProcessors/RatingFile.h"

void RatingFile::init(const std::string &fileName) {
    FileProcessing::init(fileName, {"tconst", "averageRating", "numVotes"});
}

void RatingFile::load(PackDict &tvSeries) {

    std::printf("Rate load has been started\n");

    while (!eof()) {
        auto &words = select();

        // check and add
        if (words.size() == 3 && tvSeries.contains(words.at("tconst")) && std::stoi(words.at("numVotes")) > 1000) {

            Packet &packet = tvSeries[words.at("tconst")];
            packet.rating = std::stof(words.at("averageRating"));
            packet.numVotes = std::stoi(words.at("numVotes"));
        }
    }
}
