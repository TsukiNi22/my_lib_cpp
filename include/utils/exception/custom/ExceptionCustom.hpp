/**************************************************************\
Edition:
##  @date 12/02/2026 by @author Tsukini

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
    #include "../AException.hpp"   // utils::exception::AException

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class ExceptionCustom: virtual public utils::exception::AException {
    public:
        // ------------ Operator ---------- //
        ExceptionCustom& operator=(const ExceptionCustom& object) = delete;
        ExceptionCustom& operator=(ExceptionCustom&& object) = delete;

        // ---------- Constructor --------- //
        ExceptionCustom(std::size_t type = utils::exception::None, utils::exception::Code code = utils::exception::Code::Undefined) : AException(type, code) {};
        ExceptionCustom(const ExceptionCustom& object) = delete;
        ExceptionCustom(ExceptionCustom&& object) = delete;

        // ----------- Destructor --------- //
        ~ExceptionCustom() = default;
};

} // namespace end
#endif /* EXCEPTIONCUSTOM_H */
