#pragma once
#include "FileProcessing.h"

class AkasFile : public FileProcessing {

    using packet_t = Internal::packet_t;
    using PackDict = Internal::PackDict;

public:
    AkasFile() = default;

    void init(const std::string &fileName);

    void load(PackDict &tvSeries);

private:

    const std::string id{"titleId"};
    const std::string title{"title"};
    const std::string language{"region"};

    const std::string targetLang{"RU"};

};
