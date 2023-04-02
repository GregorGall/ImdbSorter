#pragma once
#include "FileProcessing.h"

class RatingFile : public FileProcessing {

    using Packet = Internal::packet_t;
    using PackDict = Internal::PackDict;

public:
    RatingFile() = default;

    void init(std::unique_ptr<std::ifstream> fileStream);

    void load(PackDict &tvSeries);

private:

    const std::string id{ "tconst" };
    const std::string rating{ "averageRating" };
    const std::string voteNum{ "numVotes" };

    const int minVoteNum{ 1000 };

};
