qt_add_executable(purrticle main.cpp
    Viewer.cpp)
target_link_libraries(purrticle PRIVATE purrticle_core Qt6::Widgets)
