/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file WriteDefine.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef WRITEDEFINE_H
    #define WRITEDEFINE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "Color.hpp"    // utils::write::Color, utils::write::BackColor
    #include "Char.hpp"     // utils::write::Char
    #include <format>       // std::format

    //----------------------------------------------------------------//
    /* WRITEDEFINE */

    /* reset */
    #define reset   std::format("{}[0m", static_cast<char>(utils::write::Char::ESC))

    /* style */
    #define strong          std::format("{}[1m", static_cast<char>(utils::write::Char::ESC))
    #define dark            std::format("{}[2m", static_cast<char>(utils::write::Char::ESC))
    #define italic          std::format("{}[3m", static_cast<char>(utils::write::Char::ESC))
    #define underlined      std::format("{}[4m", static_cast<char>(utils::write::Char::ESC))
    #define flashing_fast   std::format("{}[5m", static_cast<char>(utils::write::Char::ESC))
    #define flashing_slow   std::format("{}[6m", static_cast<char>(utils::write::Char::ESC))
    #define reversed        std::format("{}[7m", static_cast<char>(utils::write::Char::ESC))
    #define hide            std::format("{}[8m", static_cast<char>(utils::write::Char::ESC))
    #define bar             std::format("{}[9m", static_cast<char>(utils::write::Char::ESC))

    /* cursor */
    #define load        std::format("{}[u", static_cast<char>(utils::write::Char::ESC))
    #define save        std::format("{}[s", static_cast<char>(utils::write::Char::ESC))
    #define show_cur    std::format("{}[?25h", static_cast<char>(utils::write::Char::ESC))
    #define hide_cur    std::format("{}[?25l", static_cast<char>(utils::write::Char::ESC))

    /* erase */
    #define screen_end      std::format("{}[J", static_cast<char>(utils::write::Char::ESC))
    #define screen_start    std::format("{}[1J", static_cast<char>(utils::write::Char::ESC))
    #define screen          std::format("{}[2J", static_cast<char>(utils::write::Char::ESC))
    #define line_end        std::format("{}[K", static_cast<char>(utils::write::Char::ESC))
    #define line_start      std::format("{}[1K", static_cast<char>(utils::write::Char::ESC))
    #define line            std::format("{}[2K", static_cast<char>(utils::write::Char::ESC))

#endif /* WRITEDEFINE_H */
