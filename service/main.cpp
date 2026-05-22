#include <drogon/HttpAppFramework.h>
#include <print>

import configuration;

int main() {
    /**
        1. start the configuration parser
        2. start the db connection
        3. start the redis connection
        4. start the application server
    */
    ConfigurationParser config;
    try {
        config = ConfigurationParser();
    
    } catch (const std::runtime_error& e) {
        std::println(stderr, "configuration error: {}", e.what());
        return 1;
    
    }

    

    // start
    auto service = config.get_service_configuration();
    drogon::app().addListener(service.ip_address, service.port);
    std::println("running app on {}:{}", service.ip_address, service.port);
    drogon::app().run();
    return 0;
}
