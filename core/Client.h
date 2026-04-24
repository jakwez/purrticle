#pragma once
#include "Scene.h"

namespace Core {

class Client {
   public:
    Client();
    void update(float deltaTimeSec, const std::vector<uint8_t>& data);

   private:
    Scene scene;
};

}
