#include "FileProcessors/AkasFile.h"

void AkasFile::init(const std::string &fileName) {
    FileProcessing::init(fileName, {id, title, language});
}

void AkasFile::load(PackDict &tvSeries) {

    while (!eof()) {
        auto &words = selectByFirstContains(tvSeries);

        // check and add
        if (words.size() == colNum() && words.at(language) == targetLang) {
            tvSeries[words.at(id)].title = words.at(title);
        }
    }
}
