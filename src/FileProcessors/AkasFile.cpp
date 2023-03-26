#include "FileProcessors/AkasFile.h"

void AkasFile::init(const std::string &fileName) {
    FileProcessing::init(fileName, {"titleId", "title", "region"});
}

void AkasFile::load(PackDict &tvSeries) {

    std::printf("Akas load has been started\n");

    while (!eof()) {
        auto &words = selectByFirstContains(tvSeries);

        // check and add
        if (words.size() == 3 && words.at("region") == "RU") {
            tvSeries[words.at("titleId")].title = words.at("title");
        }
    }
}
