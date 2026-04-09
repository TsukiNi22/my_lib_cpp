/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 09/04/2026 by @author Tsukini

File Name:
##  @file Hooks.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "utils/attribute/Attribute.hpp"
#include "utils/cli/Cli.hpp"
#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <cerrno>
#include <string>

hot void utils::cli::defaultPromptHook(const utils::cli::Cli& cli, std::uint8_t code)
{
    std::cout << "> " << std::flush;
}

hot utils::cli::ParsedData utils::cli::defaultParserHook(const std::string& input, bool trim, bool logic, bool parse)
{
    utils::cli::ParsedData parsedInput;

    return parsedInput;
}

hot nodiscard char utils::cli::defaultGetCHook()
{
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) != 1)
        throw std::runtime_error(strerror(errno));
    return c;
}
