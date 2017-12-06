cmake_minimum_required(VERSION 3.8)
project(hw1)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES main.cpp Board.cpp Board.h Player.cpp Player.h Cell.cpp Cell.h Game.cpp Game.h HumanPlayer.cpp HumanPlayer.h GameLogic.cpp GameLogic.h DefaultLogic.cpp DefaultLogic.h AIPlayer.cpp AIPlayer.h test/test_AIPlayer.cpp test/gtest_main.cpp test/test_Board.cpp test/test_DeafaultLogic.cpp)
add_executable(hw1 ${SOURCE_FILES})
target_link_libraries(hw1 gtest gtest_main)