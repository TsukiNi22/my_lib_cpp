/**************************************************************\
Edition:
##  @date 05/03/2026 by @author Tsukini

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
    #include "IException.hpp"               // utils::exception::IException
    #include "ExceptionDefine.hpp"          // utils::exception::Code, utils::exception::Type, utils::exception::Message
    #include "../attribute/Attribute.hpp"   // nodiscard
    #include <source_location>              // std::source_location
    #include <cstddef>                      // std::size_t
    #include <limits>                       // std::numeric_limits
    #include <string>                       // std::string

namespace utils::exception { // namespace start
//----------------------------------------------------------------//
/* CLASS */

class AException: virtual public utils::exception::IException {
    protected:
        /* Exception call info */
        std::source_location _loc;
        const char* _file = nullptr;
        const char* _func = nullptr;
        std::size_t _line = std::numeric_limits<std::size_t>::max();

        /* Exception config */
        std::string _info = "[None]";
        utils::exception::Type _type = utils::exception::Type::None;
        utils::exception::Code _code = utils::exception::Code::Undefined;

    public:
        // ----------- Function ----------- //
        std::string formated() const noexcept final;

        // ----------- Function ----------- //
        nodiscard utils::exception::Type getType() const noexcept final {return this->_type;};
        nodiscard utils::exception::Code getCode() const noexcept final {return this->_code;};
        nodiscard bool isNone() const noexcept final {return (this->_type & utils::exception::Type::None);};
        nodiscard bool isFatal() const noexcept final {return (this->_type & utils::exception::Type::Fatal);};
        nodiscard const char* what() const noexcept final {return utils::exception::Message[static_cast<std::size_t>(this->_code)];};
        nodiscard const char* info() const noexcept final {return this->_info.c_str();};
        nodiscard const std::source_location& loc() const noexcept final {return this->_loc;};
    
        // ------------ Operator ---------- //
        AException& operator=(const AException& object) = delete;
        AException& operator=(AException&& object) = delete;

        // ---------- Constructor --------- //
        AException(std::source_location loc = std::source_location::current(), utils::exception::Type type = utils::exception::Type::None, utils::exception::Code code = utils::exception::Code::Undefined, std::string info = "[None]");
        AException(const AException& object) = delete;
        AException(AException&& object) = delete;

        // ----------- Destructor --------- //
        ~AException() = default;
};

} // namespace end
#endif /* AEXCEPTION_H */
