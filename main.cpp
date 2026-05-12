#include <drogon/HttpAppFramework.h>
#include <print>

int main() {

    std::string ipaddr = "0.0.0.0";
    int16_t port = 8000;

    drogon::app().addListener(ipaddr, port);
    std::println("running app on {}:{}", ipaddr, port);
    drogon::app().run();
    return 0;
}