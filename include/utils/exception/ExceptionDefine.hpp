/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file ExceptionDefine.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef EXCEPTIONDEFINE_H
    #define EXCEPTIONDEFINE_H

    //----------------------------------------------------------------//
    /* DEFINE */
    
    /* Definition of the different return status */
    #ifndef OK
        #define OK 0 // Valid
    #endif
    #ifndef KO
        #define KO -1 // Error
    #endif

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* TYPEDEF */

/* Definition of the different exception type */
enum Type {
    None    = 0b1, // Exception like Exit, does nothing (ignore other type)
    Fatal   = 0b10,
    Error   = 0b100,
    Warning = 0b1000,
};

/* Definition of the different exception code */
enum Code {
    Undefined = 0,
};

/* Corresponding exception message for each code */
inline constexpr const char *Message[] = {
    /* Undefined */ "An undefined error has occured",
};

} // namespace end
#endif /* EXCEPTIONDEFINE_H */
