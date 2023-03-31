#include "App.h"

const int needArgumentNum       { 6 };
const std::string baseFileArg   { "base"    };
const std::string ratingFileArg { "rating"  };
const std::string episodeFileArg{ "episode" };
const std::string akasFileArg   { "akas"    };
const std::string runTimeArg    { "runTime" };

int main(int argc, char *argv[]) {

    using ptrDict = std::unordered_map<std::string, std::string*>;

    if(argc != needArgumentNum){
      std::cout << "Wrong arguments num, try again.\n";
      return -1;
    }

    input_t input;
    ptrDict inputPos {
      {baseFileArg,    &input.baseFilePath    },
      {ratingFileArg,  &input.ratingFilePath  },
      {episodeFileArg, &input.episodeFilePath },
      {akasFileArg,    &input.akasFilePath    },
      {runTimeArg,     &input.runTimeEdge     }, };

    for(int i = 1; i < argc; ++i){
      std::stringstream sstr(argv[i]);
      std::string argument, value;
      std::getline(sstr, argument, '=');
      std::getline(sstr, value);

      if(!inputPos.contains(argument)) {
        std::cout << "Unexpected argument name " << argument << " \n";
        return -1;
      }

      if(!value.size()) {
        std::cout << "Empty argument value\n";
        return -1;
      }

      *inputPos[argument] = value;
    }

    App a(input);
    return a.exec();
}
