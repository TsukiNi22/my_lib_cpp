/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file ExceptionCustom.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef EXCEPTIONCUSTOM_H
    #define EXCEPTIONCUSTOM_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../ExceptionDefine.hpp"   // utils::exception::Code, utils::exception::Type
    #include "../AException.hpp"        // utils::exception::AException
    #include <source_location>          // std::source_location
    #include <cstdint>                  // std::size_t

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ExceptionCustom: virtual public utils::exception::AException {
    public:
        // ------------ Operator ---------- //
        ExceptionCustom& operator=(const ExceptionCustom& object) = delete;
        ExceptionCustom& operator=(ExceptionCustom&& object) = delete;

        // ---------- Constructor --------- //
        ExceptionCustom(std::size_t type = utils::exception::Type::None, std::string info = "[None]", std::source_location loc = std::source_location::current()) : AException(loc, type, utils::exception::Code::Undefined, info) {};
        ExceptionCustom(std::size_t type = utils::exception::Type::None, utils::exception::Code code = utils::exception::Code::Undefined, std::string info = "[None]", std::source_location loc = std::source_location::current()) : AException(loc, type, code, info) {};
        ExceptionCustom(const ExceptionCustom& object) = delete;
        ExceptionCustom(ExceptionCustom&& object) = delete;

        // ----------- Destructor --------- //
        ~ExceptionCustom() = default;
};

} // namespace end
#endif /* EXCEPTIONCUSTOM_H */
