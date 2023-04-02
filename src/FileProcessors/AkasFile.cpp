#include "FileProcessors/AkasFile.h"

void AkasFile::init(std::unique_ptr<std::ifstream> fileStream) {
    FileProcessing::init(std::move(fileStream), {id, title, language});
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
