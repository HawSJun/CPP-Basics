#pragma once
#define ADIO_STANDALONE
#include <iostream>
#include <asio.hpp>
#include <string>

class LoginClient {
public:
    static bool tryLogin(const std::string& id, const std::string& pw) {
        try {
            asio::io_context context;
            asio::ip::tcp::resolver resolver(context);
            auto endpoints = resolver.resolve("127.0.0.1", "9000");

            asio::ip::tcp::socket socket(context);
            asio::connect(socket, endpoints);

            std::string message = id + "|" + pw + "\n";
            asio::write(socket, asio::buffer(message));

            char buffer[128];
            asio::error_code ec;
            size_t len = socket.read_some(asio::buffer(buffer), ec);
            if (ec && ec != asio::error::eof) throw std::runtime_error("read error");

            std::string response(buffer, len);
            return response.find("TRUE") != std::string::npos;
        }
        catch (...) {
            return false;
        }
    }
};
