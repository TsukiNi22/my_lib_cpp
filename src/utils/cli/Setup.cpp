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
 * bye == quit == exit -> exit the cli
*/
static void help()
{
    std::cout
    << "help:" << std::endl
    << " help\t- Display commands help" << std::endl
    << " bye\t- Exit the cli" << std::endl
    << " quit\t- Exit the cli" << std::endl
    << " exit\t- Exit the cli" << std::endl;
}
void help(unused const std::string&) {help();}
void help(unused const std::vector<std::string>&) {help();}

static void exit()
{
    throw utils::exception::NoneException(utils::exception::Code::Exit);
}
void bye() {exit();}
void quit() {exit();}

void utils::cli::Cli::resetCommands()
{
    this->_parsedCommands.clear();
    this->_rawCommands.clear();

    // Parsed commands
    using FnVec = std::function<void(const std::vector<std::string>&)>;
    this->_parsedCommands["help"] = std::make_tuple(FnVec([](unused const std::vector<std::string>& inputs){help();}), 0, 0);
    this->_parsedCommands["bye"]  = std::make_tuple(FnVec([](unused const std::vector<std::string>& inputs){bye();}), 0, 0);
    this->_parsedCommands["quit"] = std::make_tuple(FnVec([](unused const std::vector<std::string>& inputs){quit();}), 0, 0);
    this->_parsedCommands["exit"] = std::make_tuple(FnVec([](unused const std::vector<std::string>& inputs){exit();}), 0, 0);

    // Raw commands
    using FnStr = std::function<void(const std::string&)>;
    this->_rawCommands["help"] = FnStr([](unused const std::string& input){help();});
    this->_rawCommands["bye"]  = FnStr([](unused const std::string& input){bye();});
    this->_rawCommands["quit"] = FnStr([](unused const std::string& input){quit();});
    this->_rawCommands["exit"] = FnStr([](unused const std::string& input){exit();});
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
