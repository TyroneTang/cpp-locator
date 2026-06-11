module;

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <optional>
#include <format>
#include <print>
#include <cstdint>

export module mongodb;

export namespace mongodb {
    class MongoClient {
        private:
            inline static mongocxx::instance mongo_instance {};
            std::optional<mongocxx::client> client = std::nullopt;
        public:
            void connect(
                std::string_view ip_address, std::uint16_t port, std::string_view username, std::string_view password, std::string_view auth_database = "admin"
            ) {
                try {
                    std::string connection_str = std::format(
                        "mongodb://{}:{}@{}/{}", username, password, ip_address, port, auth_database
                    );

                    std::println("Connecting to mongodb at {}: {}", ip_address, port);

                    // parse to client
                    mongocxx::uri uri {connection_str};
                    client = mongocxx::client{uri};


                    // ping database for connection
                    // grab admin db and ping it
                    auto admin_db = (*client)["admin"];
                    admin_db.run_command(bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1)));

                    std::println("successfully authenticated and connected to MongoDB!")


                } catch (std::exception& e) {
                    std::println("Failed to connect to mongodb instance. Details {}", e.what());
                }
            }

    }
};