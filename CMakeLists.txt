cmake_minimum_required(VERSION 3.12)
project(sdl2_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(
        ${PROJECT_SOURCE_DIR}/include/assets/player
        ${PROJECT_SOURCE_DIR}/include/config
        ${PROJECT_SOURCE_DIR}/include/ecs
        ${PROJECT_SOURCE_DIR}/include/frame
        ${PROJECT_SOURCE_DIR}/include/game
        ${PROJECT_SOURCE_DIR}/include/input
        ${PROJECT_SOURCE_DIR}/include/logger
        ${PROJECT_SOURCE_DIR}/include/SDL2
        ${PROJECT_SOURCE_DIR}/include/texture
        ${PROJECT_SOURCE_DIR}/include/timer
)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES
        main.cpp
        include/logger/UserLog.cpp
        include/game/Game.cpp
        include/texture/Texture.cpp
        include/texture/TextureManager.cpp
        include/input/InputManager.cpp
        include/timer/Timer.cpp
        include/frame/FrameManager.cpp
        include/ecs/Entity.cpp
        include/ecs/Component.cpp
        include/ecs/TransformComponent.cpp
        include/ecs/RendererComponent.cpp
        include/ecs/ControllerComponent.cpp
        include/ecs/PhysicsComponent.cpp
        include/assets/player/Player.cpp
)

add_executable(sdl2_game ${SOURCE_FILES})

target_link_libraries(sdl2_game SDL2main SDL2 SDL2_image)