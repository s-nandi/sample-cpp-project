find_package(Catch2 CONFIG REQUIRED)

set(BENCHMARK_TARGET_NAME benchmarks)
set(BENCHMARK_SOURCE_FILES
        benchmark_main.cpp
        library_benchmarks.cpp)

add_executable(${BENCHMARK_TARGET_NAME} ${BENCHMARK_SOURCE_FILES})
target_link_libraries(${BENCHMARK_TARGET_NAME} PRIVATE ${PROJECT_NAME})
target_link_libraries(${BENCHMARK_TARGET_NAME} PRIVATE Catch2::Catch2)