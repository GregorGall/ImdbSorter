#include "App.h"

App::App(int argc, char **argv) {

    assert(argc == 6 && "Wrong arguments num, try again.\n");

    std::cout << "Input args: ";
    std::cout << std::string(argv[1]) << " " <<
                 std::string(argv[2]) << " " <<
                 std::string(argv[3]) << " " <<
                 std::string(argv[4]) << " " << std::atoi(argv[5]) << std::endl << std::endl;

    baseFile.init(argv[1]);
    ratingFile.init(argv[2]);
    episodeFile.init(argv[3]);
    akasFile.init(argv[4]);

    maxRunTime = std::atoi(argv[5]);

}

int App::exec() {

  baseFile.load(tvSeries, tvEpisodes);

  std::thread thr1(&RatingFile::load, std::ref(ratingFile), std::ref(tvSeries));
  std::thread thr2(&AkasFile::load, std::ref(akasFile), std::ref(tvSeries));
  std::thread thr3(&EpisodeFile::load, std::ref(episodeFile), std::ref(tvSeries), std::ref(tvEpisodes));

  thr3.join();
  thr2.join();
  thr1.join();

  std::cout << "\nLoad has been finished\n";

  std::multiset<Packet> topTen;
  for(auto& packet: tvSeries) {
    if(packet.second.runTime < maxRunTime){
      topTen.insert(packet.second);
      if(topTen.size() > 10){ topTen.erase(topTen.begin()); }
    }
  }

  std::cout << std::endl << std::endl << "TOP TEN\n";
  for(auto& packet: topTen) {
    std::cout << packet;
  }

  return 0;
}


