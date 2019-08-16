find_package(Catch2 CONFIG REQUIRED)

# Helper function for constructing an executable given a test's source file
function(make_test TEST_FILE)
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    set(TEST_TARGET_NAME ${PROJECT_NAME}_${TEST_NAME})

    add_executable(${TEST_TARGET_NAME} ${TEST_FILE} test_main.cpp)
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE ${PROJECT_NAME})
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE Catch2::Catch2)
    add_test(NAME ${TEST_NAME}
            COMMAND ${PROJECT_NAME}_${TEST_NAME})
endfunction()

make_test(library_tests.cpp)
make_test(faulty_tests.cpp)