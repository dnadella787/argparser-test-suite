cmake_minimum_required(VERSION 3.14)
project(argparse-test-suite)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
# set(${PROJECT_NAME}_CXX_FLAGS "${${PROJECT_NAME}_CXX_FLAGS} -std=c++17")
# set(${PROJECT_NAME}_CMAKE_CXX_FLAGS "${${PROJECT_NAME}_CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_CXX_EXTENSIONS Off)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  argparser_test
  storeNormTest.cpp
  storeDeathTest.cpp 
  appendNormTest.cpp 
  appendDeathTest.cpp 
)

target_link_libraries(
  argparser_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(argparser_test)