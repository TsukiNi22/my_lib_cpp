/**************************************************************\
Edition:
##  @date 04/03/2026 by @author Tsukini

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
    #include "generated_exception_header.hpp"

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

} // namespace end
#endif /* EXCEPTIONDEFINE_H */
