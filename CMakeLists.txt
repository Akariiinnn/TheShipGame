cmake_minimum_required(VERSION 3.22)
project(TestSDL)
set(CMAKE_CXX_STANDARD 11)

set(SDL2_INCLUDE_DIR C:/SDL/SDL2-2.0.12/include)
set(SDL2_LIB_DIR C:/SDL/SDL2-2.0.12/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(TestSDL main.cpp Application.cpp Application.h ship.h ship.cpp utilities.cpp utilities.h spritesheet.cpp spritesheet.h Mouse.h ship2.cpp ship2.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)