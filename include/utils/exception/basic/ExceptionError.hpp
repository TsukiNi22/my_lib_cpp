/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file ExceptionError.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef EXCEPTIONERROR_H
    #define EXCEPTIONERROR_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../ExceptionDefine.hpp"   // utils::exception::Code, utils::exception::Type
    #include "../AException.hpp"        // utils::exception::AException
    #include <source_location>          // std::source_location

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ExceptionError: virtual public utils::exception::AException {
    public:
        // ------------ Operator ---------- //
        ExceptionError& operator=(const ExceptionError& object) = delete;
        ExceptionError& operator=(ExceptionError&& object) = delete;

        // ---------- Constructor --------- //
        ExceptionError(utils::exception::Code code = utils::exception::Code::Undefined, std::source_location loc = std::source_location::current()) : AException(loc, utils::exception::Type::Error | utils::exception::Type::Fatal, code) {};
        ExceptionError(const ExceptionError& object) = delete;
        ExceptionError(ExceptionError&& object) = delete;

        // ----------- Destructor --------- //
        ~ExceptionError() = default;
};

} // namespace end
#endif /* EXCEPTIONERROR_H */
