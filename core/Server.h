#pragma once
#include "Simulator.h"

namespace Core {

class Server {
   public:
    Server();
    std::vector<uint8_t> update(float deltaTimeSec);

   private:
    Scene scene;
    Simulator simulator;
};

}
