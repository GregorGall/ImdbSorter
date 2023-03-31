#pragma once
#include "FileProcessing.h"

class EpisodeFile : public FileProcessing {

    using packet_t = Internal::packet_t;
    using PackDict = Internal::PackDict;

public:
    EpisodeFile() = default;

    void init(const std::string &fileName);

    void load(PackDict &tvSeries, PackDict &tvEpisodes);

private:

    const std::string id{ "tconst" };
    const std::string parentId{ "parentTconst" };

};
