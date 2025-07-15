#include "database/db.hpp"

int main() {
    if (!initDB("users.db")) {
        std::cerr << "Database connection failed.\n";
        return 1;
    }

    crow::SimpleApp app;
    setupUserRoutes(app);
    app.port(8080).run();

    closeDB();  // Optional cleanup
}
