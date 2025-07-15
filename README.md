# UserAPI
This is a basic User Management API

A simple RESTful API project built using C++ with the Crow framework, MySQL (or SQLite), and CMake. This project allows basic user management — such as adding and retrieving users — with JSON API support.

---

## 📁 Project Structure

UserAPI/
├── CMakeLists.txt          ← Build config for your project
├── main.cpp                ← Entry point, starts server and routes

├── routes/
│   ├── user_routes.cpp     ← All user-related API routes
│   └── user_routes.hpp

├── controllers/
│   ├── user_controller.cpp ← Logic: Fetch/add users, call DB, return response
│   └── user_controller.hpp

├── models/
│   └── user.hpp            ← User struct (like POJO)

├── database/
│   ├── db.cpp              ← DB connection and queries (MySQL/SQLite)
│   └── db.hpp

├── include/                ← External libraries (if not using package manager)
│   ├── crow_all.h
│   └── json.hpp

└── config/
    └── config.hpp          ← DB credentials and configs




---

## ✅ Features

- RESTful API with Crow (C++)
- JSON request/response handling
- Database connection with MySQL or SQLite
- Simple project structure for learning and extension

---

## 🚀 Getting Started

Coming soon.