#pragma once
#include <iostream>
#include <set>
#include <string>
#include <thread>

#include "FileProcessors/AkasFile.h"
#include "FileProcessors/BaseFile.h"
#include "FileProcessors/EpisodeFile.h"
#include "FileProcessors/RatingFile.h"

struct input_t {

  std::string baseFilePath = "None";
  std::string ratingFilePath = "None";
  std::string episodeFilePath = "None";
  std::string akasFilePath = "None";
  std::string runTimeEdge = "None";

};

class App {

    using packet_t = Internal::packet_t;
    using PackDict = Internal::PackDict;

public:
    App(const input_t& input);

    int exec();

private:
    std::unique_ptr<std::ifstream> openFile(const std::string &fileName);

private:
    BaseFile baseFile;
    RatingFile ratingFile;
    AkasFile akasFile;
    EpisodeFile episodeFile;

    int runTimeEdge = 0;
    const int topNum = 10;

    PackDict tvSeries;
    PackDict tvEpisodes;
};
