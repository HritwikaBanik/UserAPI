#include "user_routes.hpp"
#include "controllers/user_controller.hpp"
#include "json.hpp"
#include <unordered_set>

using json = nlohmann::json;

static const std::unordered_set<std::string> allowedTables = {
    "users", "products", "orders"  // Add more as needed
};

void setupUserRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/api/<string>").methods("GET"_method)
    ([](const crow::request& req, const std::string& table) {
        if (!allowedTables.count(table)) {
            return crow::response(400, "Invalid table name");
        }
        return getAllFromTable(table);
    });

    CROW_ROUTE(app, "/api/<string>").methods("POST"_method)
    ([](const crow::request& req, const std::string& table) {
        if (!allowedTables.count(table)) {
            return crow::response(400, "Invalid table name");
        }
        json body = json::parse(req.body);
        return insertIntoTable(table, body);
    });
}
