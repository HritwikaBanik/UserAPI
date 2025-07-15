cmake_minimum_required(VERSION 3.10)
project(UserApi)
set(CMAKE_CXX_STANDARD 17)

add_executable(UserApi
    main.cpp
    routes/user_routes.cpp
    controllers/user_controller.cpp
    database/db.cpp
)

include_directories(include routes controllers models database config)
