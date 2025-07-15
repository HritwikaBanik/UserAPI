# UserAPI
This is a basic User Management API

A simple RESTful API project built using C++ with the Crow framework, MySQL (or SQLite), and CMake. This project allows basic user management — such as adding and retrieving users — with JSON API support.

---

## 📁 Project Structure

<details>
  <summary><strong>UserAPI/</strong></summary>

  - **CMakeLists.txt** – Build config for your project  
  - **main.cpp** – Entry point, starts server and routes

  <details>
    <summary><strong>routes/</strong></summary>

  - `user_routes.cpp` – All user-related API routes  
  - `user_routes.hpp`
  </details>

  <details>
    <summary><strong>controllers/</strong></summary>

  - `user_controller.cpp` – Logic: Fetch/add users, call DB, return response  
  - `user_controller.hpp`
  </details>

  <details>
    <summary><strong>models/</strong></summary>

  - `user.hpp` – User struct (like POJO)
  </details>

  <details>
    <summary><strong>database/</strong></summary>

  - `db.cpp` – DB connection and queries (MySQL/SQLite)  
  - `db.hpp`
  </details>

  <details>
    <summary><strong>include/</strong></summary>

  - `crow_all.h`  
  - `json.hpp`
  </details>

  <details>
    <summary><strong>config/</strong></summary>

  - `config.hpp` – DB credentials and configs
  </details>

</details>




---

## ✅ Features

- RESTful API with Crow (C++)
- JSON request/response handling
- Database connection with MySQL or SQLite
- Simple project structure for learning and extension

---

## 🚀 Getting Started

Coming soon.
