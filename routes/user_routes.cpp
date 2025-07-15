#include "user_routes.hpp"
#include "controllers/user_controller.hpp"
#include "json.hpp"

using json = nlohmann::json;

void setupUserRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/api/users").methods("GET"_method)([]() {
        return getAllUsersJSON();  // Returns JSON string
    });

    CROW_ROUTE(app, "/api/users").methods("POST"_method)([](const crow::request& req) {
        auto body = json::parse(req.body);
        return createUserFromJSON(body);
    });
}
