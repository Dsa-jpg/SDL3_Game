add_executable(${PROJECT_NAME}
        gameobjects/GameObject.cpp
        gameobjects/GameObject.h
        gameobjects/Player.cpp
        gameobjects/Player.h
)
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
