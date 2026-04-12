/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 10/04/2026 by @author Tsukini

File Name:
##  @file Hooks.cpp

File Description:
##  Default hook used for the cli
\**************************************************************/

#include "utils/attribute/Attribute.hpp"
#include "utils/cli/Cli.hpp"
#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>
#include <cerrno>
#include <string>
#include <regex>

static std::string trimString(const std::string& s)
{
    std::size_t start = s.find_first_not_of(" ");
    if (start == std::string::npos) return "";
    std::size_t end = s.find_last_not_of(" ");
    return s.substr(start, end - start + 1);
}

hot void utils::cli::defaultPromptHook(unused const utils::cli::Cli& cli, unused std::uint8_t code)
{
    std::cout << "> TEEEEEEEEEEEEEEEEEEEEEESTTTTTTTTTTTTTTTTTIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIGGGGGGGGGGGGGGGGGGGG PROMPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPT >>> OK> " << std::flush;
}

static std::vector<std::string> splitCommands(const std::string& input)
{
    std::vector<std::string> commands;
    std::regex re(R"((.*?(?:&&|\|\||;)))");
    auto begin = std::sregex_iterator(input.begin(), input.end(), re);
    std::size_t index = 0;

    // For each match
    for (auto it = begin; it != std::sregex_iterator(); ++it) {
        commands.push_back(it->str());
        index += it->length();
    }

    // Last commands in string
    if (index < input.size())
        commands.push_back(input.substr(index));

    return commands;
}

static std::vector<std::string> splitCommand(const std::string& command)
{
    std::istringstream iss(command);
    std::vector<std::string> splited;
    std::string word;

    // Separate on white space (' ', '\t')
    while (iss >> word)
        splited.push_back(word);

    return splited;
}

hot utils::cli::ParsedData utils::cli::defaultParserHook(const std::string& input, bool trim, bool logic, bool parse)
{
    utils::cli::ParsedData parsedInput;
    std::vector<std::string> commands;
    std::vector<std::string> splited;
    std::vector<std::string> data;
    std::string command;

    // Empty input
    if (input.empty()) return parsedInput;

    // Get the commands separated by '&&', '||' and ';'
    if (logic) commands = splitCommands(trimString(input));
    else commands = {input};

    // Separate each commands args
    for (const std::string& rawCommand: commands) {
        command = (trim ? trimString(rawCommand) : rawCommand);
        splited = splitCommand(command);
        if (parse) {
            data.clear();
            data.push_back(splited.front());
            for (const std::string& token: splited)
                data.push_back(token);
            data.push_back((splited.back() == "&&" || splited.back() == "||" || splited.back() == ";") ? splited.back() : "");
            parsedInput.push_back(data);
        } else {
            if (splited.back() == "&&" || splited.back() == "||" || splited.back() == ";")
                command = command.erase(command.size() - splited.back().size());
            parsedInput.push_back({
                splited.front(),
                command,
                (splited.back() == "&&" || splited.back() == "||" || splited.back() == ";") ? splited.back() : ""
            });
        }
    }

    return parsedInput;
}

hot nodiscard char utils::cli::defaultGetCHook()
{
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) != 1)
        throw std::runtime_error(strerror(errno));
    return c;
}
