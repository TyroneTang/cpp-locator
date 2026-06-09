module;

#include <string>


export module models;

export struct ServiceConfig {
    const std::string& ip_address;
    const int port;
};

export struct RedisConfig {
    const std::string& ip_address;
    const int port;
    const std::string& username;
    const std::string& password;
};

export struct QDBConfig {
    const std::string& ip_address;
    const int port;
    const std::string& username;
    const std::string& password;
};