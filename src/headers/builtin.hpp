#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif
#include "history.hpp"
#include "env.hpp"

#ifndef SUSH_BUILTIN_H
#define SUSH_BUILTIN_H
namespace sush {

namespace builtin {

int find(std::vector<std::string>& args, sush::history& hstr, sush::env& env);

void exit();

void echo(std::vector<std::string>& args, sush::env env);

void type(std::vector<std::string>& args);

//filesystem
void pwd();

void cd(std::vector<std::string>& args);

void history(sush::history& hstr);

void alias(std::vector<std::string>& args, sush::env& env);

void exprt(std::vector<std::string>& args, sush::env& env);

};
};
#endif