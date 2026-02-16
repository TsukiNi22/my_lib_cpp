/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file ExceptionNone.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef EXCEPTIONNONE_H
    #define EXCEPTIONNONE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../ExceptionDefine.hpp"   // utils::exception::Code, utils::exception::Type
    #include "../AException.hpp"        // utils::exception::AException
    #include <source_location>          // std::source_location

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ExceptionNone: virtual public utils::exception::AException {
    public:
        // ------------ Operator ---------- //
        ExceptionNone& operator=(const ExceptionNone& object) = delete;
        ExceptionNone& operator=(ExceptionNone&& object) = delete;

        // ---------- Constructor --------- //
        ExceptionNone(utils::exception::Code code = utils::exception::Code::Undefined, std::source_location loc = std::source_location::current()) : AException(loc, utils::exception::Type::None, code) {};
        ExceptionNone(const ExceptionNone& object) = delete;
        ExceptionNone(ExceptionNone&& object) = delete;

        // ----------- Destructor --------- //
        ~ExceptionNone() = default;
};

} // namespace end
#endif /* EXCEPTIONNONE_H */
