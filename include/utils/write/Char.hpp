/**************************************************************\
Edition:
##  @date 03/03/2026 by @author Tsukini

File Name:
##  @file Char.hpp

File Description:
##  Definition of some special char
\**************************************************************/

#ifndef CHAR_H
    #define CHAR_H

namespace utils::write { // namespace start
//----------------------------------------------------------------//
/* TYPEDEF */

/* special chars */
enum class Char: char {
    #ifndef EOF
        // -> Can potentialy be already defined by default with 'stdio.h'
        EOF = -1,
    #endif
    ESC = 27,
    DEL = 127,
};

} // namespace end
#endif /* CHAR_H */
