#pragma once
#include <iostream>
#include <set>
#include <string>
#include <thread>

#include "BaseFile.h"
#include "RatingFile.h"
#include "AkasFile.h"
#include "EpisodeFile.h"

class App {

  using Packet = Internal::Packet;
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

    PackDict tvSeries;
    PackDict tvEpisodes;
};
