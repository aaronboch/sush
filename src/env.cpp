
#include "headers/env.hpp"
namespace sush {

env::env() {
    //set default values
    envr["PATH"] = "/usr/bin:/usr/local/bin";
}


void env::addToPath(std::string value) {
    envr["PATH"] += ":";
    envr["PATH"] += value;
}

void env::setVariable(std::string nameAndValue) {
    std::istringstream stream(nameAndValue);
    std::string name;
    std::string value;
    getline(stream,name,'=');
    getline(stream,value);
    envr[name] = value;
}

std::string env::getVariable(std::string name) {
    if(envr.find(name) != envr.end()) {
        return envr[name];
    }
    return "";
}
//searches if a command is in one of the paths in the PATH environment variable
//returns the full path of the command if it is in one of the paths
std::string env::searchPATH(std::string cmd) {
    std::istringstream stream(envr["PATH"]);
    std::string tok;
    while(getline(stream,tok,':')) {
        tok += "/" + cmd;
        if(sush::exec::isExecutable(tok) != -1) {
            return tok;
        }
    }

    return "";
}

bool env::inAlias(std::string alias) {
    return aliases.find(alias) != aliases.end();
}


void env::setAlias(std::string aliasAndCmd) {
    std::istringstream stream(aliasAndCmd);
    std::string alias;
    std::string cmd;
    getline(stream,alias,'=');
    getline(stream,cmd);
    aliases[alias] = cmd;
}

std::string env::getAlias(std::string alias) {
    return aliases[alias];
}

void env::printAliases() {
    for(const auto& alias : aliases) {
        std::cout << "alias " << alias.first << "=" << alias.second << std::endl;
    }
}

void env::printEnvr() {
    for(const auto& elem : envr) {
        std::cout << elem.first << "=" << elem.second << std::endl;
    }
}
};