#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

#include "exec.hpp"

#ifndef SUSHENV_H
#define SUSHENV_H
class sushEnv {
public:
    sushEnv();
    void addToPath(std::string value);
    void setVariable(std::string name, std::string value);
    std::string getVariable(std::string name);
    std::string searchPATH(std::string cmd);
    bool inAlias(std::string alias);
    void setAlias(std::string alias, std::string command);
    void setAlias(std::string aliasAndCommand);
    std::string getAlias(std::string alias);
private:
    std::map<std::string,std::string> env;
    std::map<std::string,std::string> aliases;
};

#endif