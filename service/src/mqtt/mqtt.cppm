module;

#include <memory>
#include <format>
#include <print>
#include <chrono>
#include "mqtt/async_client.h"


export module mqtt;

export namespace mqtt {
    class 

    class MQTTClient {
        private:
            std::unique_ptr<mqtt::async_client> client {};

        public:
            void connect(std::string_view ip_address, std::uint16_t port, std::string username, std::string password, std::string_view client_id) {
                std::string mqtt_address = std::format("{}:{}", ip_address, port);
                
                client = std::make_unique<mqtt::async_client>(
                    mqtt_address, client_id
                );

                auto conn_options = mqtt::connect_options_builder()
                .clean_session(true)
                .keep_alive_interval(std::chrono::seconds(30))
                .user_name(username)
                .password(password)
                .finalize();
                
                try{
                    std::println("Connecting to mqtt broker at {}: {}", ip_address, port);


                } catch (const mqtt::exception& e) {
                    std::println("Failed to connect to mqtt broker at {}:{}", ip_address, port);
                }
            }
    };

}