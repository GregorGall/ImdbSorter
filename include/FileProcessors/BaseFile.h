#pragma once
#include "FileProcessing.h"

class BaseFile : public FileProcessing {

    using packet_t = Internal::packet_t;
    using PackDict = Internal::PackDict;

public:
    BaseFile() = default;

    void init(std::unique_ptr<std::ifstream> fileStream);

    void load(PackDict &tvSeries, PackDict &tvEpisodes);

private:

    const std::string id{"tconst"};
    const std::string type{"titleType"};
    const std::string title{"primaryTitle"};
    const std::string adultFlag{"isAdult"};
    const std::string runTime{"runtimeMinutes"};

    const std::string adultFlagState = "0";
    const std::string seriesType{"tvSeries"};
    const std::string episodeType{"tvEpisode"};

    const std::string undefined{"\\N"};

};
