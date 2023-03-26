#pragma once
#include <iostream>
#include <string>
#include <iomanip>

namespace Internal {

    struct Packet {

        std::string id = "None";
        std::string title = "None";
        std::string titleType = "None";
        std::string isAdult = "None";

        float rating = 0;
        int runTime = 0;
        int numVotes = 0;

        static void printHeader() {

            std::cout.setf(std::ios::left, std::ios::adjustfield);

            auto printCol = [](auto obj){ std::cout << std::setw(12) << obj; };
            auto printTitle = [](auto obj){ std::cout << std::setw(60) << obj; };

            printCol("Id");
            printCol("Titletype");
            printTitle("Title");
            printCol("IsAdult");
            printCol("NumVotes");
            printCol("Rating");
            printCol("RunTime");

            std::cout << std::endl;
        }

        friend std::ostream &operator<<(std::ostream &out, const Packet &packet) {

            out.setf(std::ios::left, std::ios::adjustfield);

            auto printCol = [&](auto obj){ out << std::setw(12) << obj; };
            auto printTitle = [&](auto obj){ out << std::setw(60) << obj; };

            printCol(packet.id);
            printCol(packet.titleType);
            printTitle(packet.title);
            printCol(packet.isAdult);
            printCol(packet.numVotes);
            printCol(packet.rating);
            printCol(packet.runTime);

            out << std::endl;
            return out;
        }

        friend bool operator<(const Packet &a, const Packet &b) {
            return a.rating < b.rating;
        }

        friend bool operator<=(const Packet &a, const Packet &b) {
            return a.rating <= b.rating;
        }

        friend bool operator>(const Packet &a, const Packet &b) {
            return a.rating > b.rating;
        }

        friend bool operator>=(const Packet &a, const Packet &b) {
            return a.rating >= b.rating;
        }

        friend bool operator==(const Packet &a, const Packet &b) {
            return a.rating == b.rating;
        }

    };

}// namespace Internal
