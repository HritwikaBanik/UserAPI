cmake_minimum_required(VERSION 3.10)
project(UserApi)
set(CMAKE_CXX_STANDARD 17)

add_executable(UserApi
    main.cpp
    routes/user_routes.cpp
    controllers/user_controller.cpp
    database/DBManager.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/routes
    ${CMAKE_SOURCE_DIR}/controllers
    ${CMAKE_SOURCE_DIR}/models
    ${CMAKE_SOURCE_DIR}/database
)

