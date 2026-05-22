module;

#include <cstdint>
#include <string>


export module models;

export struct ServiceConfig {
    const std::string& ip_address;
    const std::uint16_t& port;
};

export struct RedisConfig {
    const std::string& ip_address;
    const uint16_t& port;
    const std::string& username;
    const std::string& password;
};

export struct QDBConfig {
    const std::string& ip_address;
    const uint16_t& port;
    const std::string& username;
    const std::string& password;
};