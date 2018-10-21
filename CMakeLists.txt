cmake_minimum_required(VERSION 3.12)
project(sdl2_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(
        ${PROJECT_SOURCE_DIR}/include/SDL2
        ${PROJECT_SOURCE_DIR}/include/config
        ${PROJECT_SOURCE_DIR}/include/logger
)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp include/logger/UserLog.cpp include/logger/UserLog.h include/logger/user_log_types.h include/config/app_config.h)
add_executable(sdl2_game ${SOURCE_FILES})

target_link_libraries(sdl2_game SDL2main SDL2)