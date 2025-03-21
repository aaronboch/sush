#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif


#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_MAX_LENGTH 20

class sushHistory {
public:
    sushHistory();
    ~sushHistory();
    sushHistory(sushHistory&);
    int count();
    void write(std::string);
    void deleteLine();
    void printHistory();
private:
    std::ofstream historyFile;
};

#endif