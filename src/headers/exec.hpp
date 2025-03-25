#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

#ifndef SUSHEXEC_H
#define SUSHEXEC_H

namespace sushExec {
struct executableData {
    char* pathname;
    char** argv;
};
executableData getExecutableData(std::vector<std::string> args);
int isExecutable(std::string args);
void execute(executableData data);
};

#endif