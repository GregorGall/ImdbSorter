#pragma once
#include "FileProcessing.h"

class EpisodeFile : public FileProcessing {

  using Packet = Internal::Packet;
  using PackDict = Internal::PackDict;

public:

    EpisodeFile();

    void init(const std::string& fileName);

    void load(PackDict& tvSeries, PackDict& tvEpisodes);

};
