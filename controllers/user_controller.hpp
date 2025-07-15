#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include <string>
#include "json.hpp"

// Declare the functions used in user_routes.cpp
std::string getAllFromTable(const std::string& table);
std::string insertIntoTable(const std::string& table, const nlohmann::json& data);

#endif // USER_CONTROLLER_HPP
