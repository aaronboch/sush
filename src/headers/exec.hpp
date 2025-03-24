#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

namespace exec {
struct executableData {
    char* pathname;
    char** argv;
    unsigned int argvSize;
};
executableData getExecutableData(std::vector<std::string> args);
int isExecutable(std::vector<std::string> args);

};