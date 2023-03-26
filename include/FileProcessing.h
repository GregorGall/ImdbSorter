#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include <assert.h>
#include "Packet.h"

namespace Internal {

  using PackDict = std::unordered_map<std::string, Packet>;

}

class FileProcessing {

public:

    FileProcessing();

    ~FileProcessing();

    void init(const std::string& fileName, const std::unordered_set<std::string>& colSelects);

    bool eof() { return  file.eof(); }

protected:

    std::string nextLine();

    std::unordered_map<std::string, std::string> select();

    std::unordered_map<std::string, std::string> findById(const std::string& idName);


private:

    void openFile(const std::string& fileName);

private:

    int lastCol = 0;

    std::ifstream file;

    std::unordered_map<int, std::string> colPos;

};
