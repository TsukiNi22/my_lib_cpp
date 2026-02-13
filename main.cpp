/**************************************************************\
Edition:
##  @date 13/02/2026 by @author Tsukini

File Name:
##  @file main.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _All
#include "Utils.hpp"
#include <iostream>

int main()
{
    utils::exception::IException* e = new utils::exception::ExceptionError();
    std::cout << e->isNone() << std::endl;
    std::cout << e->isFatal() << std::endl;
    std::cout << e->what() << std::endl;
    std::cout << COLOR(utils::write::Color::Red) << e->info() << std::endl;
    std::cout << e->formated() << std::endl;
    delete e;
    return OK;
}
