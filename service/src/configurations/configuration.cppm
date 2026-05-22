module;

#include <cstdint>
#include <cstdlib>
#include <string>
#include <print>
#include <stdexcept>

export module configuration;

import models;

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

export class ConfigurationParser {
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
        }

        ServiceConfig get_service_configuration() {
            return ServiceConfig {
                .ip_address = service_ip,
                .port = service_port,
            };
        }

        RedisConfig get_redis_configuration() {
            return RedisConfig {
                .ip_address = redis_ip,
                .port = redis_port,
                .username = redis_username,
                .password = redis_password, 
            };
        }

        QDBConfig get_qdb_configuration() {
            return QDBConfig {
                .ip_address = qdb_ip,
                .port = qdb_port,
                .username = qdb_username,
                .password = qdb_password
            };
        }
};
