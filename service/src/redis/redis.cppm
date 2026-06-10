module;

#include <optional>
#include <sw/redis++/redis++.h>
#include <cstdint>
#include <format>
#include <print>

export module redis;

using namespace sw::redis;

export namespace redis {
    class RedisClient{
        private:
            std::optional<sw::redis::Redis> client = std::nullopt;
        public:
            ~RedisClient();

        void connect(std::string_view ip_address, std::uint16_t port, std::string_view username, std::string_view password) {
            try {
                std::println("connecting to redis at {}:{}", ip_address, port);
                sw::redis::ConnectionOptions options;
                options.host = std::string(ip_address);
                options.port = port;
                options.user = username;
                options.password = password;


                // connection timeout
                options.socket_timeout = std::chrono::milliseconds(5000);

                client = sw::redis::Redis(options);

                // test connection
                // directly unwarp() since it is guaranteed.
                std::println("Ping redis : {}", client->ping());


            } catch (sw::redis::Error& e) {
                std::println("Redis connection error! Details: {}", e.what());
                throw std::runtime_error(std::format("Redis connection error: {}", e.what()));
            }
        };

        sw::redis::Redis& get_client() {
            if (!client.has_value()) {
                throw std::runtime_error("Missing Redis client!");
            }

            // returns reference to the obj.
            return *client;
        }
    };
};