#ifndef DB_HPP
#define DB_HPP

#include "models/user.hpp"
#include <vector>

std::vector<User> getAllUsersFromDB();
void addUserToDB(const User& user);

#endif
