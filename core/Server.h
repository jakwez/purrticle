#pragma once
#include "Simulator.h"

namespace Core {

class Server {
   public:
    Server();
    std::vector<uint8_t> update(float deltaTimeSec);
    Scene& scene() { return _scene; }

   private:
    Scene _scene;
    Simulator _simulator;
};

}  // namespace Core
