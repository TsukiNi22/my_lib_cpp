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

#include "utils/write/ANSI.hpp"
#include "utils/write/Style.hpp"
#include <initializer_list>
#include <cstdint>
#include <format>
#include <string>

std::string resetStyle(std::initializer_list<utils::write::ResetStyle> styles)
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

std::string setStyle(std::initializer_list<utils::write::Style> styles)
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
