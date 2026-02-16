/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

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
        #define _Write
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

    /* Write */
    #ifdef _Write
        // -> Handling of the edit for the ouput/input display
        // -> Define some special char & other
        #include "utils/write/Color.hpp"    // utils::write::Color, utils::write::BackColor
        #include "utils/write/Char.hpp"     // utils::write::Char
        #include "utils/write/Define.hpp"   // utils::write::
        #include "utils/write/Macro.hpp"    // utils::write::
    #endif

#endif /* UTILS_H */
