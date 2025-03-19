#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif
/*
enum class builtin {
    NONE, EXIT, ECHO
};
*/
//builtin findBuiltin(std::string cmd);
int findBuiltin(std::vector<std::string> args);

void exit();

void echo(std::vector<std::string> args);

void type(std::vector<std::string> args);

