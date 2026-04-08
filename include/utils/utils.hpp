/**************************************************************\
Edition:
##  @date 08/04/2026 by @author Tsukini

File Name:
##  @file utils.hpp

File Description:
##  Main include for every part of the utils lib
\**************************************************************/

//----------------------------------------------------------------//
/* DEFINE */

/* Activate all include */
#ifdef _Utils
    #define _Handling
    #define _Tool
    #define _Attribute
#endif

/* Activate all handling include */
#ifdef _Handling
    #define _Exception
    #define _Write
#endif

/* Activate all tool include */
#ifdef _Tool
    #define _Vector
    #define _Concepts
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
    // -> Handling of the ANSI escape sequences
    // -> Define some special char & other
    #include "utils/write/Color.hpp"    // utils::write::Color, utils::write::BackColor
    #include "utils/write/Char.hpp"     // utils::write::Char
    #include "utils/write/Style.hpp"    // utils::write::Style, utils::write::ResetStyle
    #include "utils/write/ANSI.hpp"     // different inline function for ANSI escape sequences
    #include "utils/write/format.hpp"   // utils::write::format
#endif

/* Macro */
#ifdef _Attribute
    // -> Define/Macro of attribute & keyword for optimisation & other
    #include "utils/attribute/Attribute.hpp"    // different define/macro for optimisation & other
#endif

/* VectorX */
#ifdef _Vector
    // -> Customized vector2 & vector3 for respectively 2 & 3 value of undefined type
    #include "utils/vector/IVector.hpp" // utils::vector::IVector<T>
    #include "utils/vector/Vector2.hpp" // utils::vector::Vector2<T>
    #include "utils/vector/Vector3.hpp" // utils::vector::Vector3<T>
#endif

/* Concepts */
#ifdef _Concepts
    // -> Definition of different concepts
    #include "utils/concepts/GlobalConcepts.hpp"    // Global concepts
    #include "utils/concepts/OperationConcepts.hpp" // Operation concepts
#endif
