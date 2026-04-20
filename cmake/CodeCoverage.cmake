if(NOT ENABLE_COVERAGE)
    return()
endif()

find_program(LCOV lcov REQUIRED)
find_program(GENHTML genhtml REQUIRED)

add_custom_target(coverage
    COMMAND ${LCOV} --capture --directory ${CMAKE_BINARY_DIR} --output-file coverage.info --ignore-errors mismatch,inconsistent,unsupported,format
    COMMAND ${LCOV} --remove coverage.info '/usr/*' '/opt/homebrew/*' '*/tests/*' --output-file coverage_filtered.info --ignore-errors unused,inconsistent,unsupported,format
    COMMAND ${GENHTML} coverage_filtered.info --output-directory ${CMAKE_BINARY_DIR}/coverage_report --ignore-errors inconsistent,format
    COMMAND ${CMAKE_COMMAND} -E echo "Coverage report: ${CMAKE_BINARY_DIR}/coverage_report/index.html"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
