#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif
#include "sushHistory.hpp"

int findBuiltin(std::vector<std::string> args, sushHistory hstr);

void exit();

void echo(std::vector<std::string> args);

void type(std::vector<std::string> args);

//filesystem
void pwd();

void cd(std::vector<std::string> args);

void history(sushHistory hstr);

//TODO: missing that i want to implement
// history,alias