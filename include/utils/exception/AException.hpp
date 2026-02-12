/**************************************************************\
Edition:
##  @date 12/02/2026 by @author Tsukini

File Name:
##  @file AException.hpp

File Description:
##  Absract for the cutomized exception handling
\**************************************************************/

#ifndef AEXCEPTION_H
    #define AEXCEPTION_H
    
    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type/class */
    #include "IException.hpp"       // utils::exception::IException
    #include "ExceptionDefine.hpp"  // utils::exception::Code, utils::exception::type, utils::exception::Message

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class AException: virtual public utils::exception::IException {
    private:
        std::size_t _type = utils::exception::Type::None;
        utils::exception::Code _code = utils::exception::Code::Undefined;

    public:
        // ----------- Function ----------- //
        const char* formated() const noexcept final;

        // ----------- Function ----------- //
        utils::exception::Code getCode() const noexcept final {return this->_code;};
        bool isNone() const noexcept final {return (this->_type & utils::exception::Type::None);};
        bool isFatal() const noexcept final {return (this->_type & utils::exception::Type::Fatal);};
        const char* what() const noexcept final {return utils::exception::Message[this->_code];};
    
        // ------------ Operator ---------- //
        AException& operator=(const AException& object) = delete;
        AException& operator=(AException&& object) = delete;

        // ---------- Constructor --------- //
        AException(std::size_t type = utils::exception::Type::None, utils::exception::Code code = utils::exception::Code::Undefined) : IException(), _type{type}, _code{code} {};
        AException(const AException& object) = delete;
        AException(AException&& object) = delete;

        // ----------- Destructor --------- //
        ~AException() = default;
};

} // namespace end
#endif /* AEXCEPTION_H */
