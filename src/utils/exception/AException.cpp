/**************************************************************\
Edition:
##  @date 03/03/2026 by @author Tsukini

File Name:
##  @file AException.cpp

File Description:
##  Definition of the function used in the abstract for exception
\**************************************************************/

#include "utils/exception/ExceptionDefine.hpp"
#include "utils/exception/AException.hpp"
#include "utils/write/Color.hpp"
#include "utils/write/ANSI.hpp"
#include "utils/write/Style.hpp"
#include "utils/attribute/Attribute.hpp"
#include <sstream>
#include <string>

nodiscard std::string utils::exception::AException::formated() const noexcept
{
    std::ostringstream oss;

    // Exception type
    oss << utils::write::setStyle(utils::write::Style::Strong);
    if (this->_type & utils::exception::Type::None)
        oss << utils::write::color_rgb(175, 100, 0) << "[None]";
    else if (this->_type & utils::exception::Type::Error)
        oss << utils::write::color_rgb(205, 0, 0) << "[Error]";
    else if (this->_type & utils::exception::Type::Warning)
        oss << utils::write::color_rgb(175, 0, 175) << "[Warning]";
    oss << " " << utils::write::reset();

    // Emplacement information
    oss << utils::write::setStyle(utils::write::Style::Strong) << this->_file << ":" << this->_line << utils::write::reset() << " -> " << utils::exception::Message[this->_code] << std::endl;

    // Content
    oss << utils::write::color_rgb(175, 100, 0) << "-------------------------------------------" << utils::write::reset() << std::endl;
    oss << utils::write::color(utils::write::Color::Cyan) << this->_func << utils::write::color_rgb(175, 100, 0) << " = " << utils::write::reset() << this->_info << std::endl;
    oss << utils::write::color_rgb(175, 100, 0) << "-------------------------------------------" << utils::write::reset();

    return oss.str();
}
