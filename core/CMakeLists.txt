set(FLATBUFFERS_GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
set(FLATBUFFERS_SCHEMA ${CMAKE_CURRENT_SOURCE_DIR}/schema/scene.fbs)
set(FLATBUFFERS_GENERATED_HEADER ${FLATBUFFERS_GENERATED_DIR}/scene_generated.h)

find_program(FLATC flatc REQUIRED HINTS /opt/homebrew/bin)

add_custom_command(
    OUTPUT ${FLATBUFFERS_GENERATED_HEADER}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${FLATBUFFERS_GENERATED_DIR}
    COMMAND ${FLATC} --cpp -o ${FLATBUFFERS_GENERATED_DIR} ${FLATBUFFERS_SCHEMA}
    DEPENDS ${FLATBUFFERS_SCHEMA}
    COMMENT "Generating FlatBuffers header from scene.fbs"
)

add_custom_target(flatbuffers_generated DEPENDS ${FLATBUFFERS_GENERATED_HEADER})

add_library(purrticle_core STATIC
    MyClass.cpp
    Vector2.cpp
    Scene.cpp
)

add_dependencies(purrticle_core flatbuffers_generated)
target_include_directories(purrticle_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${FLATBUFFERS_GENERATED_DIR})
target_link_libraries(purrticle_core PUBLIC Qt6::Core flatbuffers::flatbuffers)

if(ENABLE_COVERAGE)
    target_compile_options(purrticle_core PUBLIC --coverage)
    target_link_options(purrticle_core PUBLIC --coverage)
endif()
