qt_add_executable(purrticle main.cpp
    Viewer.cpp
    Viewer.h
    Server.cpp
    Server.h
    Client.cpp
    Client.h)
target_link_libraries(purrticle PRIVATE purrticle_core Qt6::Widgets Qt6::WebSockets)
