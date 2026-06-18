module;

#include <cstdint>
#include <cstdlib>
#include <string>
#include <print>
#include <stdexcept>

export module configuration;

export import models;

namespace configuration {

std::string read_env(const char* name) {
    // inherited from c, there is no std::string, hence use char* for string.
    const char* val = std::getenv(name);
    
    // handle null pointer. fast fail.
    if (!val) throw std::runtime_error(
        std::string(name) + " env variable not set!"
    );

    return val;
};

std::uint16_t parse_port(const std::string& value) {
    int val = std::stoi(value);

    if (val < 1 || val > 65535) {
        throw std::runtime_error(
            "port out of range " + value
        );
    }

    return static_cast<uint16_t>(val);
}

} // namespace configuration (internal, non-exported helpers)

export namespace configuration {
    class ConfigurationParser {
    private:
        // service
        std::string service_ip;
        std::uint16_t service_port;
        
        // redis cache
        std::string redis_ip;
        std::uint16_t redis_port;
        std::string redis_username;
        std::string redis_password;

        // database
        std::string qdb_ip;
        std::uint16_t qdb_port;
        std::string qdb_username;
        std::string qdb_password;

        // mongodb
        std::string mongodb_ip;
        std::uint16_t mongodb_port;
        std::string mongodb_username;
        std::string mongodb_password;

        // mqtt
        std::string mqtt_ip;
        std::uint16_t mqtt_port;
        std::string mqtt_username;
        std::string mqtt_password;
        std::string mqtt_client_id;

    public:
        ConfigurationParser() {
            std::println("initializing configuration parser...");

            // extract env var
            service_ip = read_env("SERVICE_IP");
            service_port = parse_port(read_env("SERVICE_PORT"));

            redis_ip = read_env("REDIS_IP");
            redis_port = parse_port(read_env("REDIS_PORT"));
            redis_username = read_env("REDIS_USERNAME");
            redis_password = read_env("REDIS_PASSWORD");

            qdb_ip = read_env("QDB_IP");
            qdb_port = parse_port(read_env("QDB_PORT"));
            qdb_username = read_env("QDB_USERNAME");
            qdb_password = read_env("QDB_PASSWORD");

            mongodb_ip = read_env("MONGODB_IP");
            mongodb_port = parse_port(read_env("MONGODB_PORT"));
            mongodb_username = read_env("MONGODB_USERNAME");
            mongodb_password = read_env("MONGODB_PASSWORD");

            mqtt_ip = read_env("MQTT_IP");
            mqtt_port = parse_port(read_env("MQTT_PORT"));
            mqtt_username = read_env("MQTT_USERNAME");
            mqtt_password = read_env("MQTT_PASSWORD");
            mqtt_client_id = read_env("MQTT_CLIENT_ID");
        }

        models::ServiceConfig get_service_configuration() {
            return models::ServiceConfig {
                .ip_address = service_ip,
                .port = service_port,
            };
        }

        models::RedisConfig get_redis_configuration() {
            return models::RedisConfig {
                .ip_address = redis_ip,
                .port = redis_port,
                .username = redis_username,
                .password = redis_password, 
            };
        }

        models::QDBConfig get_qdb_configuration() {
            return models::QDBConfig {
                .ip_address = qdb_ip,
                .port = qdb_port,
                .username = qdb_username,
                .password = qdb_password
            };
        }

        models::MongodbConfig get_mongodb_configuration() {
            return models::MongodbConfig {
                .ip_address = mongodb_ip,
                .port = mongodb_port,
                .username = mongodb_username,
                .password = mongodb_password
            };
        }

        models::MQTTConfig get_mqtt_configuration() {
            return models::MQTTConfig {
                .ip_address = mqtt_ip,
                .port = mqtt_port,
                .username = mqtt_username,
                .password = mqtt_password,
                .client_id = mqtt_client_id,
            };
        }
    };
}
