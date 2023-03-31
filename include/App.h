#pragma once
#include <iostream>
#include <set>
#include <string>
#include <thread>

#include "FileProcessors/AkasFile.h"
#include "FileProcessors/BaseFile.h"
#include "FileProcessors/EpisodeFile.h"
#include "FileProcessors/RatingFile.h"

class App {

    using packet_t = Internal::packet_t;
    using PackDict = Internal::PackDict;

public:
    App(int argc, char **argv);

    int exec();

private:
    BaseFile baseFile;
    RatingFile ratingFile;
    AkasFile akasFile;
    EpisodeFile episodeFile;

    int maxRunTime = 0;
    const int topNum = 10;

    PackDict tvSeries;
    PackDict tvEpisodes;
};
