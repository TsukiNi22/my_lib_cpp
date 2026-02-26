/**************************************************************\
Edition:
##  @date 26/02/2026 by @author Tsukini

File Name:
##  @file AException.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "utils/exception/ExceptionDefine.hpp"  // utils::exception::Message, utils::exception::Type
#include "utils/exception/AException.hpp"       // utils::exception::AException
#include "utils/write/Color.hpp"                // utils::write::Color
#include "utils/write/WriteDefine.hpp"          // reset, strong
#include "utils/write/WriteMacro.hpp"           // color_rbg
#include "utils/attribute/Attribute.hpp"        // nodiscard
#include <sstream>                              // std::ostringstream
#include <string>                               // std::string

nodiscard std::string utils::exception::AException::formated() const noexcept
{
    std::ostringstream oss;

    // Exception type
    oss << strong;
    if (this->_type & utils::exception::Type::None)
        oss << color_rgb(175, 100, 0) << "[None]";
    else if (this->_type & utils::exception::Type::Error)
        oss << color_rgb(205, 0, 0) << "[Error]";
    else if (this->_type & utils::exception::Type::Warning)
        oss << color_rgb(175, 0, 175) << "[Warning]";
    oss << " " << reset;

    // Emplacement information
    oss << strong << this->_file << ":" << this->_line << reset << " -> " << utils::exception::Message[this->_code] << std::endl;

    // Content
    oss << color_rgb(175, 100, 0) << "-------------------------------------------" << reset << std::endl;
    oss << color(utils::write::Color::Cyan) << this->_func << color_rgb(175, 100, 0) << " = " << reset << this->_info << std::endl;
    oss << color_rgb(175, 100, 0) << "-------------------------------------------" << reset;

    return oss.str();
}
