#include "Packet.h"

void Internal::packet_t::printHeader() {

  std::cout.setf(std::ios::left);

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

std::ostream &Internal::operator<<(std::ostream &out, const packet_t &packet) {

  out.setf(std::ios::left);

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
