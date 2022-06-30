cmake_minimum_required(VERSION 3.22)
project(TestSDL)
set(CMAKE_CXX_STANDARD 11)

set(SDL2_INCLUDE_DIR C:/SDL/SDL2-2.0.12/include)
set(SDL2_LIB_DIR C:/SDL/SDL2-2.0.12/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(TestSDL main.cpp app/application.cpp app/application.h entities/ship.h entities/ship.cpp render/utilities.cpp render/utilities.h render/spritesheet.cpp render/spritesheet.h entities/ship2.h entities/ship2.cpp entities/meteorite.cpp entities/meteorite.h render/background.cpp render/background.h entities/star.cpp entities/star.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)