#pragma once
#include "Scene.h"

namespace Core {

class Client {
   public:
    Client();
    void update(float deltaTimeSec, const std::vector<uint8_t>& data);
    Scene& scene() { return _scene; }

   private:
    Scene _scene;
};

}  // namespace Core
