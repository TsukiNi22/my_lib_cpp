/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file ExceptionWarning.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef EXCEPTIONWARNING_H
    #define EXCEPTIONWARNING_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../ExceptionDefine.hpp"   // utils::exception::Code, utils::exception::Type
    #include "../AException.hpp"        // utils::exception::AException
    #include <source_location>          // std::source_location

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ExceptionWarning: virtual public utils::exception::AException {
    public:
        // ------------ Operator ---------- //
        ExceptionWarning& operator=(const ExceptionWarning& object) = delete;
        ExceptionWarning& operator=(ExceptionWarning&& object) = delete;

        // ---------- Constructor --------- //
        ExceptionWarning(utils::exception::Code code = utils::exception::Code::Undefined, std::source_location loc = std::source_location::current()) : AException(loc, utils::exception::Type::Warning, code) {};
        ExceptionWarning(const ExceptionWarning& object) = delete;
        ExceptionWarning(ExceptionWarning&& object) = delete;

        // ----------- Destructor --------- //
        ~ExceptionWarning() = default;
};

} // namespace end
#endif /* EXCEPTIONWARNING_H */
