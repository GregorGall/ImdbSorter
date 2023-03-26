#pragma once
#include "FileProcessing.h"

class RatingFile : public FileProcessing {

  using Packet = Internal::Packet;
  using PackDict = Internal::PackDict;

public:

    RatingFile();

    void init(const std::string& fileName);

    void load(PackDict& tvSeries);

};
