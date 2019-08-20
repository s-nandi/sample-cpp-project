find_package(Catch2 CONFIG REQUIRED)
include(CTest)

# Helper function for constructing an executable given a benchmark's source file
function(make_benchmark BENCHMARK_FILE)
    get_filename_component(BENCHMARK_NAME ${BENCHMARK_FILE} NAME_WE)
    set(BENCH_TARGET_NAME ${PROJECT_NAME}_${BENCHMARK_NAME})

    add_executable(${BENCH_TARGET_NAME} ${BENCHMARK_FILE} benchmark_main.cpp)
    target_link_libraries(${BENCH_TARGET_NAME} PRIVATE ${PROJECT_NAME})
    target_link_libraries(${BENCH_TARGET_NAME} PRIVATE Catch2::Catch2)
    add_test(NAME ${BENCHMARK_NAME}
            COMMAND ${PROJECT_NAME}_${BENCHMARK_NAME})
endfunction()

set(BENCHMARK_TARGET_NAME benchmarks)
set(BENCHMARK_SOURCE_FILES
        # List benchmark source files below
        library_benchmarks.cpp)

# Create executable containing all benchmarks
add_executable(${BENCHMARK_TARGET_NAME} ${BENCHMARK_SOURCE_FILES} benchmark_main.cpp)
target_link_libraries(${BENCHMARK_TARGET_NAME} PRIVATE ${PROJECT_NAME})
target_link_libraries(${BENCHMARK_TARGET_NAME} PRIVATE Catch2::Catch2)

# Craete separate ctest run for each benchmark file
foreach (SINGLE_BENCHMARK_FILE ${BENCHMARK_SOURCE_FILES})
    make_benchmark(${SINGLE_BENCHMARK_FILE})
endforeach ()
