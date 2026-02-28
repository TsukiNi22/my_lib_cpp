/**************************************************************\
Edition:
##  @date 28/02/2026 by @author Tsukini

File Name:
##  @file Color.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef COLOR_H
    #define COLOR_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <cstdint>  // std::uint8_t

namespace utils::write { // namespace start
//----------------------------------------------------------------//
/* TYPEDEF */

/* color */
enum class Color: std::uint8_t {
    Black = 30,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

/* back color */
enum class BackColor: std::uint8_t {
    Black = 40,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

} // namespace end
#endif /* COLOR_H */
