#pragma once
#include <fstream>
#include <optional>
#include <sstream>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>

#include "Packet.h"
#include <assert.h>

namespace Internal {

    using PackDict = std::unordered_map<std::string, packet_t>;
    using LineDict = std::unordered_map<std::string, std::string>;

}

class FileProcessing {

    using LineDict = Internal::LineDict;

public:
    FileProcessing() = default;

    ~FileProcessing();

    void init(std::unique_ptr<std::ifstream> fileStream, const std::unordered_set<std::string> &colSelects);

    bool eof();

    int colNum();

protected:
    const std::string &nextLine();

    const LineDict &selectByFirstContains(const std::unordered_map<std::string, Internal::packet_t> &checkStorage);

    const LineDict &select();

private:
    int lastCol = 0;

    std::unique_ptr<std::ifstream> file;

    std::unordered_map<int, std::string> colPos;

    std::string tmpLine;

    LineDict words;
};
