#pragma once
#include "FileProcessing.h"

class AkasFile : public FileProcessing {

  using Packet = Internal::Packet;
  using PackDict = Internal::PackDict;

public:

    AkasFile();

    void init(const std::string& fileName);

    void load(PackDict& tvSeries);

};
