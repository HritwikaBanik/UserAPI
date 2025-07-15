#include "DBManager.hpp"
#include <iostream>

DBManager& DBManager::getInstance() {
    static DBManager instance;
    return instance;
}

bool DBManager::connect(const std::string& dbFile) {
    if (sqlite3_open(dbFile.c_str(), &db) != SQLITE_OK) {
        std::cerr << "DB Error: " << sqlite3_errmsg(db) << "\n";
        return false;
    }
    std::cout << "Database connected.\n";

    // ✅ Create users table if it doesn't exist
    const char* createUsersTableQuery = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL
        );
    )";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, createUsersTableQuery, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Table creation failed: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}


void DBManager::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
        std::cout << "Database closed.\n";
    }
}

sqlite3* DBManager::getConnection() {
    return db;
}
