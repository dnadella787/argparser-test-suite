cmake_minimum_required(VERSION 3.14)
project(argparse-test-suite)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(${PROJECT_NAME}_CXX_FLAGS "${${PROJECT_NAME}_CXX_FLAGS} -std=c++17")
set(${PROJECT_NAME}_CMAKE_CXX_FLAGS "${${PROJECT_NAME}_CMAKE_CXX_FLAGS} -std=c++17")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  argparser_test
  argparser_test.cpp
)

target_link_libraries(
  argparser_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(argparser_test)