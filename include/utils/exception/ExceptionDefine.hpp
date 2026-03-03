/**************************************************************\
Edition:
##  @date 03/03/2026 by @author Tsukini

File Name:
##  @file ExceptionDefine.hpp

File Description:
##  Definition of the error code&message
\**************************************************************/

#ifndef EXCEPTIONDEFINE_H
    #define EXCEPTIONDEFINE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <iterator> // std::size
    #include <cstddef>  // std::size_t

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
    MouseEvent, // Used in ANSI utils::write::readMouseEvent
    CODE_SENTINEL // sentinel used for verification
};

/* Corresponding exception message for each code */
inline constexpr const char *Message[] = {
    /* Undefined */ "An undefined error has occured",
    /* MouseEvent */ "Error during the read of the mouse event",
};

// Check at the compile time the correspondece between the message & code
static_assert(std::size(Message) == static_cast<std::size_t>(utils::exception::Code::CODE_SENTINEL), "The message array doesn't correspond to the available exception codes");

} // namespace end
#endif /* EXCEPTIONDEFINE_H */
