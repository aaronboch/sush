
#include "headers/env.hpp"
namespace sush{

env::env() {
    //set default values
    envr["PATH"] = "/usr/bin:/usr/local/bin";
}


void env::addToPath(std::string value) {
    envr["PATH"] += ":";
    envr["PATH"] += value;
}

void env::setVariable(std::string name, std::string value) {
    envr[name] = value;
}

std::string env::getVariable(std::string name) {
    if(envr.find(name) != envr.end()) {
        return envr[name];
    }
    return "";
}

std::string env::searchPATH(std::string cmd){
    std::istringstream stream(envr["PATH"]);
    std::string tok;
    while(getline(stream,tok,':')){
        tok += "/" + cmd;
        if(sush::exec::isExecutable(tok) != -1){
            return tok;
        }
    }

    return "";
}

bool env::inAlias(std::string alias){
    return aliases.find(alias) != aliases.end();
}

void env::setAlias(std::string alias, std::string cmd){
    aliases[alias] = cmd;
}

void env::setAlias(std::string aliasAndCmd){
    std::istringstream stream(aliasAndCmd);
    std::string alias;
    std::string cmd;
    getline(stream,alias,'=');
    getline(stream,cmd);
    aliases[alias] = cmd;
}

std::string env::getAlias(std::string alias){
    return aliases[alias];
}
};