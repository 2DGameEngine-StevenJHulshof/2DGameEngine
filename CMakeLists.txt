cmake_minimum_required(VERSION 3.12)
project(2DGameEngine)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
endif (WIN32)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif (UNIX)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(
        ${PROJECT_SOURCE_DIR}/game
        ${PROJECT_SOURCE_DIR}/include/SDL2
        ${PROJECT_SOURCE_DIR}/src/2DPlatformer
        ${PROJECT_SOURCE_DIR}/src/2DPlatformer/components
        ${PROJECT_SOURCE_DIR}/src/collision
        ${PROJECT_SOURCE_DIR}/src/config
        ${PROJECT_SOURCE_DIR}/src/ecs/components/base
        ${PROJECT_SOURCE_DIR}/src/ecs/components
        ${PROJECT_SOURCE_DIR}/src/ecs/entity
        ${PROJECT_SOURCE_DIR}/src/engine
        ${PROJECT_SOURCE_DIR}/src/font
        ${PROJECT_SOURCE_DIR}/src/frame
        ${PROJECT_SOURCE_DIR}/src/input
        ${PROJECT_SOURCE_DIR}/src/logger
        ${PROJECT_SOURCE_DIR}/src/manager
        ${PROJECT_SOURCE_DIR}/src/texture
        ${PROJECT_SOURCE_DIR}/src/timer
        ${PROJECT_SOURCE_DIR}/src/vector
)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES
        main.cpp
        game/Game.cpp
        src/config/game_config.cpp
        src/logger/UserLog.cpp
        src/engine/GameEngine.cpp
        src/texture/Texture.cpp
        src/texture/TextureManager.cpp
        src/font/SDL_FontCache.c
        src/font/Font.cpp
        src/font/FontManager.cpp
        src/input/InputManager.cpp
        src/frame/FrameManager.cpp
        src/collision/CollisionManager.cpp
        src/timer/Timer.cpp
        src/vector/Vector2D.cpp
        src/ecs/entity/Entity.cpp
        src/ecs/entity/EntityManager.cpp
        src/ecs/components/base/Component.cpp
        src/ecs/components/base/ComponentManager.cpp
        src/ecs/components/Transform.cpp
        src/ecs/components/Renderer.cpp
        src/ecs/components/Input.cpp
        src/ecs/components/Collider.cpp
        src/ecs/components/Physics.cpp
        src/2DPlatformer/components/Platform2DTransform.cpp
        src/2DPlatformer/components/Platform2DRenderer.cpp
        src/2DPlatformer/components/Platform2DInput.cpp
        src/2DPlatformer/components/Platform2DPhysics.cpp
        src/2DPlatformer/components/Platform2DCollider.cpp
        src/2DPlatformer/components/Platform2DDynamicCollider.cpp
)

add_executable(2DGameEngine ${SOURCE_FILES})

target_link_libraries(2DGameEngine SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
