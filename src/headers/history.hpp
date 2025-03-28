#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif


#ifndef SUSH_HISTORY_H
#define SUSH_HISTORY_H

#define HISTORY_MAX_LENGTH 20
namespace sush {
class history {
public:
    history();
    ~history();
    history(history&);
    int count();
    void write(std::string);
    void deleteLine();
    void printHistory();
private:
    std::ofstream historyFile;
};
};
#endif