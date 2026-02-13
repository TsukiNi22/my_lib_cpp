/**************************************************************\
Edition:
##  @date 13/02/2026 by @author Tsukini

File Name:
##  @file Macro.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef MACRO_H
    #define MACRO_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "Color.hpp"    // utils::write::Color, utils::write::BackColor
    #include "Char.hpp"     // utils::write::Char
    #include <cstdint>      // std::uint8_t
    #include <format>       // std::format

    //----------------------------------------------------------------//
    /* MACRO */

    /* color */
    #define COLOR(c)                std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(c)).c_str()
    #define COLOR_RGB(r, g, b)      std::format("{}[38;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b)).c_str()
    #define BACK_COLOR_RGB(r, g, b) std::format("{}[48;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b)).c_str()

#endif /* MACRO_H */
