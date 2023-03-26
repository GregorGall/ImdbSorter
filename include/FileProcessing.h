#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <optional>

#include <assert.h>
#include "Packet.h"

namespace Internal {

  using PackDict = std::unordered_map<std::string, Packet>;

}

class FileProcessing {

  using LineDict = std::unordered_map<std::string, std::string>;

public:

    FileProcessing();

    ~FileProcessing();

    void init(const std::string& fileName, const std::unordered_set<std::string>& colSelects);

    bool eof() { return  file.eof(); }

protected:

    const std::string& nextLine();

    const LineDict& selectByFirstContains(const std::unordered_map<std::string, Internal::Packet>& checkStorage);

    const LineDict& select();

private:

    void openFile(const std::string& fileName);

private:

    int lastCol = 0;

    std::ifstream file;

    std::unordered_map<int, std::string> colPos;

    std::string tmpLine;

    LineDict words;

};
