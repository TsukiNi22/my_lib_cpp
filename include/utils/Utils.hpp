/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

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
        #define _Attribute
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
        #include "utils/exception/basic/NoneException.hpp"      // utils::exception::NoneException
        #include "utils/exception/basic/ErrorException.hpp"     // utils::exception::ErrorException
        #include "utils/exception/basic/WarningException.hpp"   // utils::exception::WarningException
        #include "utils/exception/custom/CustomException.hpp"   // utils::exception::CustomException
    #endif

    /* Write */
    #ifdef _Write
        // -> Handling of the edit for the ouput/input display
        // -> Define some special char & other
        #include "utils/write/Color.hpp"        // utils::write::Color, utils::write::BackColor
        #include "utils/write/Char.hpp"         // utils::write::Char
        #include "utils/write/WriteDefine.hpp"  // different define for ouput edition
        #include "utils/write/WriteMacro.hpp"   // different macro for ouput edition
    #endif

    /* Macro */
    #ifdef _Attribute
        // -> Define/Macro of attribute & keyword for optimisation & other
        #include "utils/attribute/Attribute.hpp"  // different define/macro for optimisation & other
    #endif

#endif /* UTILS_H */
