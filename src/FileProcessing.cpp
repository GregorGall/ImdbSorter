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

std::string FileProcessing::nextLine() {
    std::string line;
    std::getline(file, line);
    return line;
}

std::unordered_map<std::string, std::string> FileProcessing::findById(const std::string& idName)
{
  while(!file.eof()) {

    std::string nLine = nextLine();

    if(nLine.compare(0, idName.size(), idName) == 0) {
      file.seekg(int(file.tellg()) - nLine.size());
      return select();
    };

  }

  return {};
}

std::unordered_map<std::string, std::string> FileProcessing::select() {

  std::unordered_map<std::string, std::string> words;

    std::stringstream sstr(nextLine());
    for(int i = 0 ; i <= lastCol; ++i) {

      std::string column;
      std::getline(sstr, column, '\t');

      if(colPos.contains(i) && column.size()) {
        words[colPos[i]] = column;
      }
    }

    return words;
}


FileProcessing::~FileProcessing() {
    file.close();
}
