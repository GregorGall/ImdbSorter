#include "BaseFile.h"

BaseFile::BaseFile() {
}

void BaseFile::init(const std::string& fileName) {
  FileProcessing::init(fileName, {"tconst", "titleType", "primaryTitle", "isAdult", "runtimeMinutes"});
}

void BaseFile::load(PackDict& tvSeries, PackDict& tvEpisodes) {

  std::cout << "Base load has been started\n";
  while(!eof()) {
    auto words = select();

    bool valid = words.size() == 5 && words["isAdult"] == "0";

    if( valid && words["titleType"] == "tvSeries") {
      Packet packet;
      packet.id = words["tconst"];
      packet.titleType = words["titleType"];
      packet.title = words["primaryTitle"];
      packet.isAdult = words["isAdult"];
      packet.runTime = 0;

      tvSeries[packet.id] = packet;
    }
    else if ( valid && words["titleType"] == "tvEpisode" && words["runtimeMinutes"] != "\\N") {
      Packet packet;
      packet.id = words["tconst"];
      packet.runTime = std::stoi(words["runtimeMinutes"]);

      tvEpisodes[packet.id] = packet;
    }
  }

}

