#include "crow_all.h"
#include "routes/user_routes.hpp"

int main() {
    crow::SimpleApp app;
    setupUserRoutes(app);  // Register routes from routes file
    app.port(8080).run();
}
