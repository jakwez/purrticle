add_library(purrticle_core STATIC
    MyClass.cpp
    Vector2.cpp
    Scene.cpp
)

target_include_directories(purrticle_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(purrticle_core PUBLIC Qt6::Core)

if(ENABLE_COVERAGE)
    target_compile_options(purrticle_core PUBLIC --coverage)
    target_link_options(purrticle_core PUBLIC --coverage)
endif()
