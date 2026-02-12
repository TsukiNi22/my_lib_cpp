/**************************************************************\
Edition:
##  @date 12/02/2026 by @author Tsukini

File Name:
##  @file Utils.hpp

File Description:
##  
\**************************************************************/

#ifndef UTILS_H
    #define UTILS_H

    //----------------------------------------------------------------//
    /* DEFINE */

    /* Activate all include */
    #ifdef _All
        #define _Handling
    #endif

    /* Activate all handling include */
    #ifdef _Handling
        #define _Exception
    #endif

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* Exception */
    #ifdef _Exception
        // -> Customized exception used for the error/warning handling
        #include "utils/exception/IException.hpp"               // utils::exception::IException
        #include "utils/exception/ExceptionDefine.hpp"          // OK/KO, utils::exception::Code, utils::exception::Type
        #include "utils/exception/basic/ExceptionNone.hpp"      // utils::exception::None
        #include "utils/exception/basic/ExceptionError.hpp"     // utils::exception::Error
        #include "utils/exception/basic/ExceptionWarning.hpp"   // utils::exception::Warning
        #include "utils/exception/custom/ExceptionCustom.hpp"   // utils::exception::Custom
    #endif

#endif /* UTILS_H */
