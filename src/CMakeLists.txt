add_executable(${PROJECT_NAME}
        core/GameObject.cpp
        core/GameObject.h
        core/PhysicsBody.cpp
        core/PhysicsBody.h
        core/Collision.cpp
        core/Collision.h
        gameobjects/Square.cpp
        gameobjects/Square.h
        core/Vec2.h
        core/Transform.h
        gameobjects/Circle.cpp
        gameobjects/Circle.h
        core/Common.h
)
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)
