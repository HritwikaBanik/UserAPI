#include "DBManager.hpp"
#include "user.hpp"
#include "json.hpp"
#include <sqlite3.h>
#include <sstream>

using json = nlohmann::json;

template <typename T>
std::string join(const std::vector<T>& vec, const std::string& delim) {
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i != vec.size() - 1) oss << delim;
    }
    return oss.str();
}


std::string getAllFromTable(const std::string& table) {
    sqlite3* db = DBManager::getInstance().getConnection();
    std::stringstream query;
    query << "SELECT * FROM " << table << ";";

    sqlite3_stmt* stmt;
    std::vector<json> rows;

    if (sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        int cols = sqlite3_column_count(stmt);
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            json row;
            for (int i = 0; i < cols; ++i) {
                const char* colName = sqlite3_column_name(stmt, i);
                const unsigned char* val = sqlite3_column_text(stmt, i);
                row[colName] = val ? reinterpret_cast<const char*>(val) : "";
            }
            rows.push_back(row);
        }
    }
    sqlite3_finalize(stmt);
    return json(rows).dump();
}

std::string insertIntoTable(const std::string& table, const json& data) {
    sqlite3* db = DBManager::getInstance().getConnection();

    std::vector<std::string> keys, placeholders;
    std::vector<std::string> values;

    for (auto& el : data.items()) {
        keys.push_back(el.key());
        placeholders.push_back("?");
        values.push_back(el.value().get<std::string>());
    }

    std::stringstream query;
    query << "INSERT INTO " << table << " ("
          << join(keys, ",") << ") VALUES ("
          << join(placeholders, ",") << ");";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return json({{"error", "prepare failed"}}).dump();
    }

    for (size_t i = 0; i < values.size(); ++i) {
        sqlite3_bind_text(stmt, static_cast<int>(i + 1), values[i].c_str(), -1, SQLITE_TRANSIENT);
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return json({{"error", "insert failed"}}).dump();
    }

    sqlite3_finalize(stmt);
    return json({{"status", "success"}}).dump();
}
