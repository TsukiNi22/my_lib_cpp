/**************************************************************\
Edition:
##  @date 13/02/2026 by @author Tsukini

File Name:
##  @file Char.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
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
};

} // namespace end
#endif /* CHAR_H */
