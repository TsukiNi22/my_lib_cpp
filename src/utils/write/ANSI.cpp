/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 03/03/2026 by @author Tsukini

File Name:
##  @file ANSI.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "utils/exception/ExceptionDefine.hpp"
#include "utils/exception/custom/CustomException.hpp"
#include "utils/write/ANSI.hpp"
#include "utils/write/Style.hpp"
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <format>
#include <string>

std::string utils::write::resetStyle(std::initializer_list<utils::write::ResetStyle> styles)
{
    std::string s_styles;

    bool first = true;
    for (const utils::write::ResetStyle& style : styles) {
        if (!first) s_styles += ";";
        s_styles += std::to_string(static_cast<std::uint8_t>(style));
        first = false;
    }

    // Empty list -> reset all style
    if (styles.size() == 0)
        s_styles = "0";

    return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), s_styles);
}

std::string utils::write::setStyle(std::initializer_list<utils::write::Style> styles)
{
    std::string s_styles;

    bool first = true;
    for (const utils::write::Style& style : styles) {
        if (!first) s_styles += ";";
        s_styles += std::to_string(static_cast<std::uint8_t>(style));
        first = false;
    }

    return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), s_styles);
}

// Report format -> "ESC[Mb;x;y"
utils::write::MouseEvent utils::write::readMouseEvent()
{
    utils::write::MouseEvent event;
    std::string buffer;
    char c = '\0';

    // Get the input
    bool started = false;
    for (std::size_t i = 0; std::cin.get(c) && i < 128; ++i)
    {
        if (c == static_cast<char>(utils::write::Char::ESC)) started = true;
        if (started) buffer += c;
        if (started && std::isdigit(c)) continue;
        if (started && c == '\n') break;
    }

    // Check the buffer
    if (buffer.size() < 6)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, "Mouse sequence too short");
    if (buffer.find("[M") == std::string::npos)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, "Invalid classic mouse format");

    // Get the start of the data
    auto start = buffer.find('M');

    // Setup the data extraction
    std::stringstream ss(buffer.substr(start + 1));
    std::string token;

    // Get the different data
    int cb = 0;
    try {
        if (!std::getline(ss, token, ';'))
            throw std::runtime_error("Missing button field");
        cb = std::stoi(token);
        if (!std::getline(ss, token, ';'))
            throw std::runtime_error("Missing X field");
        event.x = std::stoul(token);
        if (!std::getline(ss, token, ';'))
            throw std::runtime_error("Missing Y field");
        event.y = std::stoul(token);
    } catch (const std::exception& e) {
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, std::format("{}: {}", "Failed parsing classic mouse event", e.what()));
    }

    // Convert the button value
    switch (cb & 0b11) {
        case 0: event.button = utils::write::MouseButton::Left;        break;
        case 1: event.button = utils::write::MouseButton::Middle;      break;
        case 2: event.button = utils::write::MouseButton::Right;       break;
        case 3: event.button = utils::write::MouseButton::Release;     break;
        default: event.button = utils::write::MouseButton::Unknown;    break;
    }

    return event;
}

// Report format -> "ESC[<b;x;y(M|m)"
utils::write::AdvancedMouseEvent utils::write::readAdvancedMouseEvent()
{
    utils::write::AdvancedMouseEvent event;
    std::string buffer;
    char c = '\0';

    // Get the input until 'M' or 'm'
    bool started = false;
    for (std::size_t i = 0; std::cin.get(c) && i < 128; ++i) { // Limitation of 128 char to counter infinite possible loop
        if (c == static_cast<char>(utils::write::Char::ESC)) started = true;
        if (started) buffer += c;
        if (started && (c == 'M' || c == 'm')) break;
    }

    // Check the buffer
    if (buffer.empty())
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, "No mouse sequence received");
    if (buffer.size() < 8)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, "Mouse sequence too short");
    if (buffer.find("[<") == std::string::npos)
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, "Invalid SGR mouse format");

    // Button status
    event.pressed = (buffer.back() == 'M');

    // Get the start of the data
    auto start = buffer.find('<');

    // Setup the data extraction
    std::stringstream ss(buffer.substr(start + 1));
    std::string token;

    // Get the different data
    int cb = 0;
    try {
        if (!std::getline(ss, token, ';'))
            throw std::runtime_error("Missing button field");
        cb = std::stoi(token);
        if (!std::getline(ss, token, ';'))
            throw std::runtime_error("Missing X field");
        event.x = std::stoul(token);
        if (!std::getline(ss, token, ';'))
            throw std::runtime_error("Missing Y field");
        event.y = std::stoul(token);
    } catch (const std::exception& e) {
        throw utils::exception::CustomException(utils::exception::Type::Error, utils::exception::Code::MouseEvent, std::format("{}: {}", "Failed parsing classic mouse event", e.what()));
    }

    // Convert the button value
    switch (cb & 0b11) {
        case 0: event.button = utils::write::MouseButton::Left;        break;
        case 1: event.button = utils::write::MouseButton::Middle;      break;
        case 2: event.button = utils::write::MouseButton::Right;       break;
        case 3: event.button = utils::write::MouseButton::Release;     break;
        default: event.button = utils::write::MouseButton::Unknown;    break;
    }

    return event;
}
