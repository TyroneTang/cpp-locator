module;

#include <questdb/ingress/line_sender.hpp>
#include <libpq-fe.h>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <print>

export module quest_client;

import std;


// export type

export class QuestDBClient {
    public:
        QuestDBClient(
            const std::string& host, 
            const std::uint16_t port, 
            const std::string& username, 
            const std::string& password
        );

        ~QuestDBClient();

        // Non-copyable — each instance owns a live TCP connection
        QuestDBClient(const QuestDBClient&)            = delete;
        QuestDBClient& operator=(const QuestDBClient&) = delete;

        // Movable
        QuestDBClient(QuestDBClient&&)            = default;
        QuestDBClient& operator=(QuestDBClient&&) = default;

        // health
        [[nodiscard]] auto is_alive() -> bool;
};


// implementation
QuestDBClient::QuestDBClient(
    const std::string& host, 
    const std::uint16_t port, 
    const std::string& username, 
    const std::string& password
) 
    : sender_()

{

};