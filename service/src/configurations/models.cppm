module;
#include <cstdint>
#include <string>


export module models;

export namespace configuration::models {
    struct ServiceConfig {
        const std::string& ip_address;
        const std::uint16_t port;
    };
    struct RedisConfig {
        const std::string& ip_address;
        const std::uint16_t port;
        const std::string& username;
        const std::string& password;
    };
    struct QDBConfig {
        const std::string& ip_address;
        const std::uint16_t port;
        const std::string& username;
        const std::string& password;
    };
    struct MongodbConfig {
        const std::string& ip_address;
        const std::uint16_t port;
        const std::string& username;
        const std::string& password;
    };
}