#include "user_controller.hpp"
#include "database/db.hpp"
#include "models/user.hpp"
#include "json.hpp"

using json = nlohmann::json;

std::string getAllUsersJSON() {
    std::vector<User> users = getAllUsersFromDB();
    json j = json::array();
    for (const auto& user : users) {
        j.push_back({{"id", user.id}, {"name", user.name}, {"email", user.email}});
    }
    return j.dump();
}

std::string createUserFromJSON(const json& data) {
    User newUser = {0, data["name"], data["email"]};
    addUserToDB(newUser);
    return json({{"status", "success"}}).dump();
}
