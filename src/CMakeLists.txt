add_executable(${PROJECT_NAME}
        gameobjects/GameObject.cpp
        gameobjects/GameObject.h
        gameobjects/PhysicsBody.cpp
        gameobjects/PhysicsBody.h
        gameobjects/Collision.cpp
        gameobjects/Collision.h
        gameobjects/Square.cpp
        gameobjects/Square.h
        gameobjects/Floor.cpp
        gameobjects/Floor.h
)
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
