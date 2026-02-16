/**************************************************************\
Edition:
##  @date 16/02/2026 by @author Tsukini

File Name:
##  @file main.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#define _All
#include "utils/Utils.hpp"
#include <iostream>

int main()
{
    utils::exception::IException* e = new utils::exception::ErrorException();
    std::cout << e->isNone() << std::endl;
    std::cout << e->isFatal() << std::endl;
    std::cout << e->what() << std::endl;
    std::cout << e->info() << std::endl;
    std::cout << e->formated() << std::endl;
    delete e;
    return OK;
}
