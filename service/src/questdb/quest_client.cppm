module;

#include <questdb/ingress/line_sender.hpp>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <print>

export module quest_client;

// export type

export class QuestDBClient {
    private:    
        std::optional<questdb::ingress::line_sender> client = std::nullopt;
    
    public:
    void conenct(std::string_view host, std::uint16_t port, std::string_view username, std::string_view password) {
        
    }
};      


// // implementation
// QuestDBClient::QuestDBClient(
//     const std::string& host, 
//     const std::uint16_t port, 
//     const std::string& username, 
//     const std::string& password
// ) 
//     : sender_()

// {

// };