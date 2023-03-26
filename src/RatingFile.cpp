#include "RatingFile.h"

RatingFile::RatingFile() {
}

void RatingFile::init(const std::string& fileName) {
  FileProcessing::init(fileName, {"tconst", "averageRating", "numVotes"});
}

void RatingFile::load(PackDict& tvSeries) {

  std::cout << "Rate load has been started\n";
  PackDict reduced;

  while(!eof()) {
    auto words = select();

    // check and add
    if( words.size() == 3 && tvSeries.contains(words["tconst"]) && std::stoi(words["numVotes"]) > 1000) {

      Packet& packet = tvSeries[words["tconst"]];
      packet.rating = std::stof(words["averageRating"]);
      packet.numVotes = std::stoi(words["numVotes"]);

      reduced[words["tconst"]] = packet;
    }
  }

  tvSeries = reduced;
}
