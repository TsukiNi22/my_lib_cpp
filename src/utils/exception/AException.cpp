/**************************************************************\
Edition:
##  @date 03/03/2026 by @author Tsukini

File Name:
##  @file AException.cpp

File Description:
##  Definition of the function used in the abstract for exception
\**************************************************************/

#include "utils/exception/ExceptionDefine.hpp"  // utils::exception::Message, utils::exception::Type
#include "utils/exception/AException.hpp"       // utils::exception::AException
#include "utils/write/Color.hpp"                // utils::write::Color
#include "utils/write/OutputEdition.hpp"        // utils::write::reset, utils::write::strong, utils::write::color_rbg
#include "utils/attribute/Attribute.hpp"        // nodiscard
#include <sstream>                              // std::ostringstream
#include <string>                               // std::string

nodiscard std::string utils::exception::AException::formated() const noexcept
{
    std::ostringstream oss;

    // Exception type
    oss << utils::write::strong();
    if (this->_type & utils::exception::Type::None)
        oss << utils::write::color_rgb(175, 100, 0) << "[None]";
    else if (this->_type & utils::exception::Type::Error)
        oss << utils::write::color_rgb(205, 0, 0) << "[Error]";
    else if (this->_type & utils::exception::Type::Warning)
        oss << utils::write::color_rgb(175, 0, 175) << "[Warning]";
    oss << " " << utils::write::reset();

    // Emplacement information
    oss << utils::write::strong() << this->_file << ":" << this->_line << utils::write::reset() << " -> " << utils::exception::Message[this->_code] << std::endl;

    // Content
    oss << utils::write::color_rgb(175, 100, 0) << "-------------------------------------------" << utils::write::reset() << std::endl;
    oss << utils::write::color(utils::write::Color::Cyan) << this->_func << utils::write::color_rgb(175, 100, 0) << " = " << utils::write::reset() << this->_info << std::endl;
    oss << utils::write::color_rgb(175, 100, 0) << "-------------------------------------------" << utils::write::reset();

    return oss.str();
}
