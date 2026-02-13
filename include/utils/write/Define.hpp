/**************************************************************\
Edition:
##  @date 13/02/2026 by @author Tsukini

File Name:
##  @file Define.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef DEFINE_H
    #define DEFINE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "Color.hpp"    // utils::write::Color, utils::write::BackColor
    #include "Char.hpp"     // utils::write::Char
    #include <format>       // std::format

    //----------------------------------------------------------------//
    /* DEFINE */

    /* reset */
    #define RESET   std::format("{}[0m", static_cast<char>(utils::write::Char::ESC)).c_str()

#endif /* DEFINE_H */
