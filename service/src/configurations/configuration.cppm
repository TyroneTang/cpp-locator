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
        std::string sql_ip;
        std::uint16_t sql_port;
        std::string sql_username;
        std::string sql_password;

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

            sql_ip = read_env("SQL_IP");
            sql_port = parse_port(read_env("SQL_PORT"));
            sql_username = read_env("SQL_USERNAME");
            sql_password = read_env("SQL_PASSWORD");
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

        SQLConfig get_sql_configuration() {
            return SQLConfig {
                .ip_address = sql_ip,
                .port = sql_port,
                .username = sql_username,
                .password = sql_password
            };
        }
};
