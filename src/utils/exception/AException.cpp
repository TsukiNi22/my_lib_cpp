/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file AException.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "utils/exception/ExceptionDefine.hpp"  // utils::exception::Message
#include "utils/exception/AException.hpp"       // utils::exception::AException
#include <sstream>                              // std::ostringstream
#include <string>                               // std::string

std::string utils::exception::AException::formated()
const noexcept {
    std::ostringstream oss;
    //oss << ;
    return oss.str();
}
