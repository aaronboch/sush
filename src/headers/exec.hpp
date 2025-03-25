#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

#ifndef SUSH_EXEC_H
#define SUSH_EXEC_H

namespace sush {
    namespace exec{
struct executableData {
    char* pathname;
    char** argv;
};
executableData getExecutableData(std::vector<std::string> args);
int isExecutable(std::string args);
void execute(executableData& data);
};
};

#endif