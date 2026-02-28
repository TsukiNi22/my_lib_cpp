/**************************************************************\
Edition:
##  @date 28/02/2026 by @author Tsukini

File Name:
##  @file OutputEdition.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef OUTPUTEDITION_H
    #define OUTPUTEDITION_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "Color.hpp"    // utils::write::Color, utils::write::BackColor
    #include "Char.hpp"     // utils::write::Char
    #include <cstdint>      // std::uint8_t
    #include <format>       // std::format
    #include <string>       // std::string

namespace utils::write { // namespace start
    //----------------------------------------------------------------//
    /* OUTPUTEDITION */

    /* ----------- reset ----------- */
    inline std::string reset()  {return std::format("{}[0m", static_cast<char>(utils::write::Char::ESC));}

    /* ----------- style ----------- */
    inline std::string strong()         {return std::format("{}[1m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string dark()           {return std::format("{}[2m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string italic()         {return std::format("{}[3m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string underlined()     {return std::format("{}[4m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string flashing_fast()  {return std::format("{}[5m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string flashing_slow()  {return std::format("{}[6m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string reversed()       {return std::format("{}[7m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string hide()           {return std::format("{}[8m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string bar()            {return std::format("{}[9m", static_cast<char>(utils::write::Char::ESC));}
    /* args */
    inline std::string color(utils::write::Color c)                                     {return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(c));}
    inline std::string color(utils::write::BackColor c)                                 {return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(c));}
    inline std::string color_rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)        {return std::format("{}[38;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), r, g, b);}
    inline std::string back_color_rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)   {return std::format("{}[48;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), r, g, b);}

    /* ---------- cursor ----------- */
    inline std::string load()       {return std::format("{}[u", static_cast<char>(utils::write::Char::ESC));}
    inline std::string save()       {return std::format("{}[s", static_cast<char>(utils::write::Char::ESC));}
    inline std::string show_cur()   {return std::format("{}[?25h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string hide_cur()   {return std::format("{}[?25l", static_cast<char>(utils::write::Char::ESC));}
    /* args */
    inline std::string up(int32_t n)                {return std::format("{}[{}A", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string down(int32_t n)              {return std::format("{}[{}B", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string right(int32_t n)             {return std::format("{}[{}C", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string left(int32_t n)              {return std::format("{}[{}D", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string next_line(int32_t n)         {return std::format("{}[{}E", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string previous_line(int32_t n)     {return std::format("{}[{}F", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string column(int32_t x)            {return std::format("{}[{}G", static_cast<char>(utils::write::Char::ESC), x);}
    inline std::string pos(int32_t x, int32_t y)    {return std::format("{}[{};{}H", static_cast<char>(utils::write::Char::ESC), x, y);}

    /* ----------- erase ----------- */
    inline std::string screen_end()     {return std::format("{}[J", static_cast<char>(utils::write::Char::ESC));}
    inline std::string screen_start()   {return std::format("{}[1J", static_cast<char>(utils::write::Char::ESC));}
    inline std::string screen()         {return std::format("{}[2J", static_cast<char>(utils::write::Char::ESC));}
    inline std::string line_end()       {return std::format("{}[K", static_cast<char>(utils::write::Char::ESC));}
    inline std::string line_start()     {return std::format("{}[1K", static_cast<char>(utils::write::Char::ESC));}
    inline std::string line()           {return std::format("{}[2K", static_cast<char>(utils::write::Char::ESC));}

} // namespace ends
#endif /* OUTPUTEDITION_H */
