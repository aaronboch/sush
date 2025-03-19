#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

enum class builtin {
    NONE, EXIT
};

builtin findBuiltin(std::string cmd);

void exit();

