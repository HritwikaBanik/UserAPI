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
