add_library(purrticle_lib STATIC
    MyClass.cpp
)

target_include_directories(purrticle_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(purrticle_lib PUBLIC Qt6::Core Qt6::Widgets)

if(ENABLE_COVERAGE)
    target_compile_options(purrticle_lib PUBLIC --coverage)
    target_link_options(purrticle_lib PUBLIC --coverage)
endif()

qt_add_executable(purrticle main.cpp)
target_link_libraries(purrticle PRIVATE purrticle_lib)
