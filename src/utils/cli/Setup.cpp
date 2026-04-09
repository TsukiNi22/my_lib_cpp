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
##  @file Setup.cpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#include "utils/attribute/Attribute.hpp"
#include "utils/exception/ExceptionDefine.hpp"
#include "utils/exception/basic/NoneException.hpp"
#include "utils/cli/Cli.hpp"
#include <termios.h>
#include <functional>
#include <iostream>
#include <cstdint>
#include <csignal>
#include <vector>
#include <string>
#include <tuple>

utils::cli::Cli::Cli()
{
    // Setup initial values
    this->resetCommands();
    this->resetHooks();
    this->resetMiddlewares();

    // Setup the term
    tcgetattr(STDIN_FILENO, &this->_orig);
    termios raw = this->_orig;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Signal handling
    std::signal(SIGINT, SIG_IGN); // ctrl+c
    std::signal(SIGTSTP, SIG_IGN); // ctrl+z
}

utils::cli::Cli::~Cli()
{
    // Reset the term
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &this->_orig);

    // Reset signal
    std::signal(SIGINT, SIG_DFL); // ctrl+c
    std::signal(SIGTSTP, SIG_DFL); // ctrl+z
}

/* Default commands
 * help -> display commands help
 * bey == quit == exit -> exit the cli
*/
static void help()
{
    std::cout
    << "help:" << std::endl
    << " help\t- Display commands help" << std::endl
    << " bey\t- Exit the cli" << std::endl
    << " quit\t- Exit the cli" << std::endl
    << " exit\t- Exit the cli" << std::endl;
}
void help(unused const std::string&) {help();}
void help(unused const std::vector<std::string>&) {help();}

static void exit()
{
    throw utils::exception::NoneException(utils::exception::Code::Exit);
}
void bey(unused const std::string&) {exit();}
void bey(unused const std::vector<std::string>&) {exit();}
void quit(unused const std::string&) {exit();}
void quit(unused const std::vector<std::string>&) {exit();}
void exit(unused const std::string&) {exit();}
void exit(unused const std::vector<std::string>&) {exit();}

void utils::cli::Cli::resetCommands()
{
    this->_parsedCommands.clear();
    this->_rawCommands.clear();

    // Parsed commands
    using FnVec = std::function<void(const std::vector<std::string>&)>;
    this->_parsedCommands["help"] = std::make_tuple(FnVec([](const std::vector<std::string>& inputs){help(inputs);}), 0, 0);
    this->_parsedCommands["bey"]  = std::make_tuple(FnVec([](const std::vector<std::string>& inputs){bey(inputs);}), 0, 0);
    this->_parsedCommands["quit"] = std::make_tuple(FnVec([](const std::vector<std::string>& inputs){quit(inputs);}), 0, 0);
    this->_parsedCommands["exit"] = std::make_tuple(FnVec([](const std::vector<std::string>& inputs){exit(inputs);}), 0, 0);

    // Raw commands
    using FnStr = std::function<void(const std::string&)>;
    this->_rawCommands["help"] = FnStr([](const std::string& input){help(input);});
    this->_rawCommands["bey"]  = FnStr([](const std::string& input){bey(input);});
    this->_rawCommands["quit"] = FnStr([](const std::string& input){quit(input);});
    this->_rawCommands["exit"] = FnStr([](const std::string& input){exit(input);});
}

void utils::cli::Cli::resetHooks()
{
    this->resetPromptHook();
    this->resetParserHook();
    this->resetGetCHook();
}

void utils::cli::Cli::resetMiddlewares()
{
    this->cliMiddlewares.clear();
    this->errorMiddlewares.clear();
    this->promptMiddlewares.clear();
    this->inputMiddlewares.clear();
    this->parserMiddlewares.clear();
    this->execMiddlewares.clear();
    this->commandMiddlewares.clear();
}
