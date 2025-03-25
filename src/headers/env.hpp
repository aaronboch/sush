#ifndef COMMON_H
#define COMMON_H
#include "common.hpp"
#endif

#include "exec.hpp"

#ifndef SUSH_ENV_H
#define SUSH_ENV_H
namespace sush {
class env {
public:
    env();
    void addToPath(std::string value);
    void setVariable(std::string nameAndValue);
    std::string getVariable(std::string name);
    std::string searchPATH(std::string cmd);
    bool inAlias(std::string alias);
    void setAlias(std::string aliasAndCommand);
    std::string getAlias(std::string alias);
    void printAliases();
    void printEnvr();

private:
    std::map<std::string,std::string> envr;
    std::map<std::string,std::string> aliases;
};
};
#endif