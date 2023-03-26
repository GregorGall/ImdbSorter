#include "EpisodeFile.h"

EpisodeFile::EpisodeFile() {
}

void EpisodeFile::init(const std::string& fileName) {
  FileProcessing::init(fileName, {"tconst", "parentTconst"});
}

void EpisodeFile::load(PackDict& tvSeries, PackDict& tvEpisodes) {

  std::cout << "Episode load has been started\n";
  while(!eof()) {
    auto words = select();

    // check and add
    if( words.size() == 2 && tvSeries.contains(words["parentTconst"]) && tvEpisodes.contains(words["tconst"]) ) {
      Packet& packet = tvSeries[words["parentTconst"]];
      packet.runTime += tvEpisodes[words["tconst"]].runTime;
    }
  }

}

