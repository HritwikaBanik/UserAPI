#include "database/DBManager.hpp"  
#include "user_routes.hpp"          
#include "crow_all.h"               
int main() {
    // Connect to the database
    if (!DBManager::getInstance().connect("users.db")) {
        std::cerr << "Database connection failed.\n";
        return 1;
    }

    // Start the Crow web server
    crow::SimpleApp app;
    setupUserRoutes(app);  // Register API routes

    app.port(8080).run();  // Run the server on port 8080

    // Optional: Clean up the DB connection
    DBManager::getInstance().close();

    return 0;
}
