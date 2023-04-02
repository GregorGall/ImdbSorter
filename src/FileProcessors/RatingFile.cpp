#include "FileProcessors/RatingFile.h"

void RatingFile::init(std::unique_ptr<std::ifstream> fileStream) {
    FileProcessing::init(std::move(fileStream), {id, rating, voteNum});
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
