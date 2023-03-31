#include "FileProcessors/RatingFile.h"

void RatingFile::init(const std::string &fileName) {
    FileProcessing::init(fileName, {id, rating, voteNum});
}

void RatingFile::load(PackDict &tvSeries) {

    while (!eof()) {
        auto &words = select();
        bool valid = words.size() == colNum() && tvSeries.contains(words.at(id));

        // check and add
        if (valid && std::stoi(words.at(voteNum)) > minVoteNum) {

            Packet &packet = tvSeries[words.at(id)];
            packet.rating = std::stof(words.at(rating));
            packet.numVotes = std::stoi(words.at(voteNum));
        }
    }
}
