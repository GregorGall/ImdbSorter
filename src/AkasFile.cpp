#include "AkasFile.h"

AkasFile::AkasFile() {
}

void AkasFile::init(const std::string& fileName) {
  FileProcessing::init(fileName, {"titleId", "title", "region"});
}

void AkasFile::load(PackDict& tvSeries) {

  std::printf("Akas load has been started\n");

  while(!eof()) {
    auto words = select();

    // check and add
    if( words.size() == 3 && tvSeries.contains(words["titleId"]) && words["region"] == "RU" ) {
      tvSeries[words["titleId"]].title = words["title"];
    }
  }

}

