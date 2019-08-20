find_package(Catch2 CONFIG REQUIRED)
include(CTest)

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

set(TESTING_TARGET_NAME ${PROJECT_NAME}_testing)
set(TEST_SOURCE_FILES
        # List test source files below
        library_tests.cpp
        faulty_tests.cpp)

# Create executable containing all tests
add_executable(${TESTING_TARGET_NAME} ${TEST_SOURCE_FILES} test_main.cpp)
target_link_libraries(${TESTING_TARGET_NAME} PRIVATE ${PROJECT_NAME})
target_link_libraries(${TESTING_TARGET_NAME} PRIVATE Catch2::Catch2)

# Craete separate ctest run for each test file
foreach (SINGLE_TEST_FILE ${TEST_SOURCE_FILES})
    make_test(${SINGLE_TEST_FILE})
endforeach ()
