#pragma once
#include <sqlite3.h>
#include <string>

class DBManager {
public:
    static DBManager& getInstance();
    bool connect(const std::string& dbFile);
    void close();
    sqlite3* getConnection();

private:
    DBManager() = default;
    ~DBManager() = default;

    sqlite3* db = nullptr;
    DBManager(const DBManager&) = delete;
    DBManager& operator=(const DBManager&) = delete;
};
