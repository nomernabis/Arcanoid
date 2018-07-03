cmake_minimum_required(VERSION 3.2)
project(Arcanoid)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(UI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sfmlgui)
add_subdirectory(sfmlgui)

include_directories(${UI_INCLUDE_DIR})



set(SOURCE_FILES main.cpp Game.cpp Game.h states/State.cpp states/State.h states/MenuState.cpp states/MenuState.h states/GameState.cpp states/GameState.h game/Paddle.cpp game/Paddle.h game/Ball.cpp game/Ball.h)
add_executable(Arcanoid ${SOURCE_FILES})

target_link_libraries(Arcanoid ui)
add_dependencies(Arcanoid ui)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Arcanoid ${SFML_LIBRARIES})
endif()
