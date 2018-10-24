cmake_minimum_required(VERSION 3.12)
project(2DGameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(
        ${PROJECT_SOURCE_DIR}/include/SDL2
        ${PROJECT_SOURCE_DIR}/src/config
        ${PROJECT_SOURCE_DIR}/src/ecs
        ${PROJECT_SOURCE_DIR}/src/frame
        ${PROJECT_SOURCE_DIR}/src/engine
        ${PROJECT_SOURCE_DIR}/src/input
        ${PROJECT_SOURCE_DIR}/src/logger
        ${PROJECT_SOURCE_DIR}/src/texture
        ${PROJECT_SOURCE_DIR}/src/timer
)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES
        main.cpp
        src/logger/UserLog.cpp
        src/engine/GameEngine.cpp
        src/texture/Texture.cpp
        src/texture/TextureManager.cpp
        src/input/InputManager.cpp
        src/timer/Timer.cpp
        src/frame/FrameManager.cpp
        src/ecs/Entity.cpp
        src/ecs/Component.cpp
        src/ecs/TransformComponent.cpp
        src/ecs/RendererComponent.cpp
        src/ecs/ControllerComponent.cpp
        src/ecs/PhysicsComponent.cpp
)

add_executable(2DGameEngine ${SOURCE_FILES})

target_link_libraries(2DGameEngine SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)