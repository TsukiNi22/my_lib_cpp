/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file WriteMacro.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef WRITEMACRO_H
    #define WRITEMACRO_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "Color.hpp"    // utils::write::Color, utils::write::BackColor
    #include "Char.hpp"     // utils::write::Char
    #include <cstdint>      // std::uint8_t
    #include <format>       // std::format

    //----------------------------------------------------------------//
    /* WRITEMACRO */

    /* color */
    #define color(c)                std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(c))
    #define color_rgb(r, g, b)      std::format("{}[38;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b))
    #define back_color_rgb(r, g, b) std::format("{}[48;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b))

    /* cursor */
    #define up(n)               std::format("{}[{}A", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(n))
    #define down(n)             std::format("{}[{}B", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(n))
    #define right(n)            std::format("{}[{}C", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(n))
    #define left(n)             std::format("{}[{}D", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(n))
    #define next_line(n)        std::format("{}[{}E", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(n))
    #define previous_line(n)    std::format("{}[{}F", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(n))
    #define column(x)           std::format("{}[{}G", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(x))
    #define pos(x, y)           std::format("{}[{};{}H", static_cast<char>(utils::write::Char::ESC), static_cast<int32_t>(x), static_cast<int32_t>(y))

#endif /* WRITEMACRO_H */
