/**************************************************************\
Edition:
##  @date 03/03/2026 by @author Tsukini

File Name:
##  @file ANSI.hpp

File Description:
##  Definition of ANSI escape sequences
\**************************************************************/

#ifndef ANSI_H
    #define ANSI_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "Color.hpp"        // utils::write::Color, utils::write::BackColor
    #include "Char.hpp"         // utils::write::Char
    #include "Style.hpp"        // utils::write::Style, utils::write::ResetStyle
    #include <initializer_list> // std::initializer_list
    #include <cstdint>          // std::uint8_t
    #include <format>           // std::format
    #include <string>           // std::string

namespace utils::write { // namespace start
    //----------------------------------------------------------------//
    /* ANSI */

    /* ----------- reset ----------- */
    inline std::string reset()                                      {return std::format("{}[0m", static_cast<char>(utils::write::Char::ESC));}
    inline std::string resetStyle(utils::write::ResetStyle style)   {return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(style));}
    std::string resetStyle(std::initializer_list<utils::write::ResetStyle> styles);

    /* ----------- style ----------- */
    inline std::string setStyle(utils::write::Style style)          {return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(style));}
    std::string setStyle(std::initializer_list<utils::write::Style> styles);
    /* args */
    inline std::string color(utils::write::Color c)                                         {return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(c));}
    inline std::string color(utils::write::BackColor c)                                     {return std::format("{}[{}m", static_cast<char>(utils::write::Char::ESC), static_cast<std::uint8_t>(c));}
    inline std::string color_id(std::uint8_t id)                                            {return std::format("{}[38;5;{}m", static_cast<char>(utils::write::Char::ESC), id);}
    inline std::string back_color_id(std::uint8_t id)                                       {return std::format("{}[48;5;{}m", static_cast<char>(utils::write::Char::ESC), id);}
    inline std::string underline_color_id(std::uint8_t id)                                  {return std::format("{}[58;5;{}m", static_cast<char>(utils::write::Char::ESC), id);}
    inline std::string color_rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)            {return std::format("{}[38;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), r, g, b);}
    inline std::string back_color_rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)       {return std::format("{}[48;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), r, g, b);}
    inline std::string underline_color_rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)  {return std::format("{}[58;2;{};{};{}m", static_cast<char>(utils::write::Char::ESC), r, g, b);}

    /* ---------- cursor ----------- */
    inline std::string load_cur()   {return std::format("{}[u", static_cast<char>(utils::write::Char::ESC));}
    inline std::string save_cur()   {return std::format("{}[s", static_cast<char>(utils::write::Char::ESC));}
    /* args */
    inline std::string up(int32_t n)                {return std::format("{}[{}A", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string down(int32_t n)              {return std::format("{}[{}B", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string right(int32_t n)             {return std::format("{}[{}C", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string left(int32_t n)              {return std::format("{}[{}D", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string next_line(int32_t n)         {return std::format("{}[{}E", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string previous_line(int32_t n)     {return std::format("{}[{}F", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string column(int32_t x)            {return std::format("{}[{}G", static_cast<char>(utils::write::Char::ESC), x);}
    inline std::string pos(int32_t x, int32_t y)    {return std::format("{}[{};{}H", static_cast<char>(utils::write::Char::ESC), x, y);}
    inline std::string scroll_up(int32_t n)         {return std::format("{}[{}S", static_cast<char>(utils::write::Char::ESC), n);}
    inline std::string scroll_down(int32_t n)       {return std::format("{}[{}T", static_cast<char>(utils::write::Char::ESC), n);}

    /* ----------- erase ----------- */
    inline std::string screen_end()         {return std::format("{}[0J", static_cast<char>(utils::write::Char::ESC));}
    inline std::string screen_start()       {return std::format("{}[1J", static_cast<char>(utils::write::Char::ESC));}
    inline std::string screen()             {return std::format("{}[2J", static_cast<char>(utils::write::Char::ESC));}
    inline std::string scrollback_buffer()  {return std::format("{}[3J", static_cast<char>(utils::write::Char::ESC));} // Can delete the term history
    inline std::string line_end()           {return std::format("{}[0K", static_cast<char>(utils::write::Char::ESC));}
    inline std::string line_start()         {return std::format("{}[1K", static_cast<char>(utils::write::Char::ESC));}
    inline std::string line()               {return std::format("{}[2K", static_cast<char>(utils::write::Char::ESC));}

    /* ------ private-modes ------- */
    inline std::string inverted_color_enable()  {return std::format("{}[?5h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string inverted_color_disable() {return std::format("{}[?5l", static_cast<char>(utils::write::Char::ESC));}
    inline std::string wrapping_enable()        {return std::format("{}[?7h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string wrapping_disable()       {return std::format("{}[?7l", static_cast<char>(utils::write::Char::ESC));}
    inline std::string show_cur()               {return std::format("{}[?25h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string hide_cur()               {return std::format("{}[?25l", static_cast<char>(utils::write::Char::ESC));}
    inline std::string save_screen()            {return std::format("{}[?1049h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string load_screen()            {return std::format("{}[?1049l", static_cast<char>(utils::write::Char::ESC));}
    
    /* --------- reports ---------- */
    inline std::string get_pos()                        {return std::format("{}[6n", static_cast<char>(utils::write::Char::ESC));} // Reports cursor position as "ESC[y;xR"
    inline std::string mouse_tracking_enable()          {return std::format("{}[?1000h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string mouse_tracking_disable()         {return std::format("{}[?1000l", static_cast<char>(utils::write::Char::ESC));}
    inline std::string mouse_move_tracking_enable()     {return std::format("{}[?1002h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string mouse_move_tracking_disable()    {return std::format("{}[?1002l", static_cast<char>(utils::write::Char::ESC));}
    // Reports mouse action as (each x&y value as a '+ 32') "ESC[Mb;x;y" -> 'b' is the boutton & modifier
    // Boutton: 0 left, 1 mid, 2 right, 3 release
    // Modifer: +4 shift, +8 alt, +16 ctrl
    inline std::string mouse_adv_tracking_enable()      {return std::format("{}[?1006h", static_cast<char>(utils::write::Char::ESC));}
    inline std::string mouse_adv_tracking_disable()     {return std::format("{}[?1006l", static_cast<char>(utils::write::Char::ESC));}
    // Reports mouse action as "ESC[<b;x;y(M|m)" -> 'b' is the boutton & modifier -> M = pressed, m = released
    // Boutton: 0 left, 1 mid, 2 right, 3 release
    // Modifer: +4 shift, +8 alt, +16 ctrl
    inline std::string report_focus_enable()            {return std::format("{}[?1004h", static_cast<char>(utils::write::Char::ESC));} // Focus in: "ESC[I" | Focus out: "ESC[O"
    inline std::string report_focus_disabled()          {return std::format("{}[?1004l", static_cast<char>(utils::write::Char::ESC));}
    inline std::string report_past_enable()             {return std::format("{}[?2004h", static_cast<char>(utils::write::Char::ESC));} // Reports for pasted data: "ESC[200~{data}ESC[201~"
    inline std::string report_past_disable()            {return std::format("{}[?2004l", static_cast<char>(utils::write::Char::ESC));}

} // namespace ends
#endif /* ANSI_H */
