include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt5 COMPONENTS Core REQUIRED)

add_executable(awari
    main.cpp
    Game.cpp
    Player.cpp
)

target_link_libraries(awari Qt5::Core)