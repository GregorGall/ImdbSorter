#pragma once
#include <iostream>
#include <string>

namespace Internal {

  struct Packet {

    std::string id = "None";
    std::string title = "None";
    std::string titleType = "None";
    std::string isAdult = "None";

    float rating = -1;
    int runTime = -1;
    int numVotes = -1;

    static void printHeader() {
      std::cout << "Id\t Titletype\t ";
      std::cout.width(50);
      std::cout << "Title\t IsAdult\t NumVotes\t Rating\t RunTime" << std::endl;
    }

    friend bool operator<(const Packet& a, const Packet& b) {
      return a.rating < b.rating;
    }

    friend bool operator>(const Packet& a, const Packet& b) {
      return a.rating > b.rating;
    }

    friend std::ostream& operator<<(std::ostream& out, const Packet& packet){
      out << packet.id << " \t" << packet.titleType << " \t";
      out.width(50);
      out << packet.title << " \t" << packet.isAdult << " \t";
      out << packet.numVotes << " \t" << packet.rating << " \t" << packet.runTime << std::endl;
      return out;
    }

  };

}
