#include "db.hpp"
#include <sqlite3.h>
#include <iostream>

std::vector<User> getAllUsersFromDB() {
    sqlite3* db;
    std::vector<User> users;

    if (sqlite3_open("users.db", &db) == SQLITE_OK) {
        const char* query = "SELECT id, name, email FROM users;";
        sqlite3_stmt* stmt;
        
        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                User user;
                user.id = sqlite3_column_int(stmt, 0);
                user.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                user.email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                users.push_back(user);
            }
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Failed to open DB\n";
    }

    sqlite3_close(db);
    return users;
}

void addUserToDB(const User& user) {
    sqlite3* db;
    if (sqlite3_open("users.db", &db) == SQLITE_OK) {
        const char* query = "INSERT INTO users (name, email) VALUES (?, ?);";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, user.name.c_str(), -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, user.email.c_str(), -1, SQLITE_TRANSIENT);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Failed to insert user\n";
            }
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
}
