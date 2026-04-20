enable_testing()

add_executable(purrticle_tests
    MyClassTest.cpp
)

target_include_directories(purrticle_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(purrticle_tests PRIVATE GTest::gtest_main purrticle_lib)

include(GoogleTest)
gtest_discover_tests(purrticle_tests)

if(ENABLE_COVERAGE)
    target_compile_options(purrticle_tests PRIVATE --coverage)
    target_link_options(purrticle_tests PRIVATE --coverage)
endif()
