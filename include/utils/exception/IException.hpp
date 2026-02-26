/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file IException.hpp

File Description:
##  Interface for the cutomized exception handling
\**************************************************************/

#ifndef IEXCEPTION_H
    #define IEXCEPTION_H
    
    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type/class */
    #include "ExceptionDefine.hpp"  // utils::exception::Code, utils::exception::type
    #include <exception>            // std::exception
    #include <string>               // std::string

namespace utils::exception { // namespace start

//----------------------------------------------------------------//
/* CLASS */

class IException: virtual public std::exception {
    public:
        // --------- Pre-Function --------- //
        virtual utils::exception::Code getCode() const noexcept = 0;
        virtual bool isNone() const noexcept = 0;
        virtual bool isFatal() const noexcept = 0;
        virtual const char* what() const noexcept = 0;
        virtual const char* info() const noexcept = 0;
        virtual std::string formated() const noexcept = 0;

        // ------------ Operator ---------- //
        IException& operator=(const IException& object) = delete;
        IException& operator=(IException&& object) = delete;

        // ---------- Constructor --------- //
        IException() = default;
        IException(const IException& object) = delete;
        IException(IException&& object) = delete;

        // ----------- Destructor --------- //
        ~IException() = default;
};

} // namespace end
#endif /* IEXCEPTION_H */
