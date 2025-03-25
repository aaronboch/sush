#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

#include "exec.hpp"


class sushEnv {
public:
    sushEnv();
    void addToPath(std::string value);
    void setVariable(std::string name, std::string value);
    std::string getVariable(std::string name);
    std::string searchPATH(std::string cmd);
private:
    std::map<std::string,std::string> env;

};
