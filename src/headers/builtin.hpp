#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

int findBuiltin(std::vector<std::string> args);

void exit();

void echo(std::vector<std::string> args);

void type(std::vector<std::string> args);

//filesystem
void pwd();

void cd(std::vector<std::string> args);


//TODO: missing that i want to implement
// cd,history,alias