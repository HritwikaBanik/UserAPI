#ifndef USER_CONTROLLER_HPP
#define USER_CONTROLLER_HPP

#include "json.hpp"

std::string getAllUsersJSON();
std::string createUserFromJSON(const nlohmann::json& data);

#endif
