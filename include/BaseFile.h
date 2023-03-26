#pragma once
#include "FileProcessing.h"

class BaseFile : public FileProcessing {

  using Packet = Internal::Packet;
  using PackDict = Internal::PackDict;

public:

    BaseFile();

    void init(const std::string& fileName);

    void load(PackDict& tvSeries, PackDict& tvEpisodes);

};
