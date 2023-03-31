#pragma once
#include <iostream>
#include <string>
#include <iomanip>

namespace Internal {

    struct packet_t {

        std::string id = "None";
        std::string title = "None";
        std::string titleType = "None";
        std::string isAdult = "None";

        float rating = 0;
        int runTime = 0;
        int numVotes = 0;

        static void printHeader();

        friend std::ostream &operator<<(std::ostream &out, const packet_t &packet);

        friend bool operator<(const packet_t &a, const packet_t &b) {
            return a.rating < b.rating;
        }

        friend bool operator<=(const packet_t &a, const packet_t &b) {
            return a.rating <= b.rating;
        }

        friend bool operator>(const packet_t &a, const packet_t &b) {
            return a.rating > b.rating;
        }

        friend bool operator>=(const packet_t &a, const packet_t &b) {
            return a.rating >= b.rating;
        }

        friend bool operator==(const packet_t &a, const packet_t &b) {
            return a.rating == b.rating;
        }

    };

}// namespace Internal
