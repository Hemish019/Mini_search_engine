cmake_minimum_required(VERSION 3.15)
project(MiniSearchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find the system CURL library
find_package(CURL REQUIRED)

# 2. Gather main source files (excluding main.cpp so we don't get double main() errors in tests)
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")
list(FILTER ALL_SOURCES EXCLUDE REGEX "src/main.cpp$")

# 3. Define the main search engine executable
add_executable(search_engine src/main.cpp ${ALL_SOURCES})
target_include_directories(search_engine PRIVATE include)
target_link_libraries(search_engine PRIVATE CURL::libcurl)

# =================================================================
# TESTING SETUP
# =================================================================

# 4. Gather all test files from the tests/ directory
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# 5. Create a separate executable for running tests
if(TEST_SOURCES)
    add_executable(run_tests ${TEST_SOURCES} ${ALL_SOURCES})
    target_include_directories(run_tests PRIVATE include)
    target_link_libraries(run_tests PRIVATE CURL::libcurl)
endif()
