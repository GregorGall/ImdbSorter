#include "FileProcessing.h"
#include <algorithm>

FileProcessing::FileProcessing() {
}

void FileProcessing::openFile(const std::string& fileName) {
    file.open(fileName);
    assert(file.is_open() && "File open error");
}

void FileProcessing::init(const std::string& fileName, const std::unordered_set<std::string>& colSelects) {

    openFile(fileName);

    int count = 0;
    std::stringstream sstr(nextLine());
    while(!sstr.eof()) {

      std::string column;
      std::getline(sstr, column, '\t');

      if(colSelects.contains(column)) {
        colPos[count] = column;
        lastCol = count;
      }

      ++count;
    }

}

const std::string& FileProcessing::nextLine() {
    std::getline(file, tmpLine);
    return tmpLine;
}

const FileProcessing::LineDict& FileProcessing::select() {

    std::stringstream sstr(nextLine());
    for(int i = 0 ; i <= lastCol; ++i) {

      std::getline(sstr, tmpLine, '\t');
      if(colPos.contains(i)) {
        words[colPos[i]] = tmpLine;
      }

    }

    return words;
}

const FileProcessing::LineDict& FileProcessing::selectByFirstContains(const std::unordered_map<std::string, Internal::Packet>& checkStorage) {

  std::stringstream sstr(nextLine());
  std::getline(sstr, tmpLine, '\t');

  if(checkStorage.contains(tmpLine)) {

    sstr.seekg(0);
    for(int i = 0 ; i <= lastCol; ++i) {
      std::getline(sstr, tmpLine, '\t');
      if(colPos.contains(i)) {
        words[colPos[i]] = tmpLine;
      }
    }

    return words;
  };

  words.clear();
  return words;
}


FileProcessing::~FileProcessing() {
    file.close();
}
