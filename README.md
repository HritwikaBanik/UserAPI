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

<h2>✅ Features</h2>

<p>A lightweight, modular C++ API designed for learning and extensibility:</p>

<ul>
  <li>🔗 <strong>RESTful API</strong> built with <a href="https://github.com/CrowCpp/crow" target="_blank">Crow</a> – a fast and expressive C++ microframework</li>
  <li>📦 <strong>JSON-based request &amp; response handling</strong> with clean, readable structures</li>
  <li>🗄️ <strong>Database connectivity</strong> using <code>MySQL</code> or <code>SQLite</code> – choose what suits your use case</li>
  <li>🧱 <strong>Modular project structure</strong> that separates routes, controllers, models, and DB logic for easy scaling</li>
  <li>🚀 <strong>Minimal setup</strong> — ideal for C++ developers exploring web development and backend design</li>
  <li>🛠️ Designed to be <strong>easily extendable</strong> for features like authentication, file uploads, and more</li>
</ul>

---

## 🚀 Getting Started

Coming soon.
