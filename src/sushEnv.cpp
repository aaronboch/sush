
#include "headers/sushEnv.hpp"

sushEnv::sushEnv() {
    //set default values
    env["PATH"] = "/usr/bin:/usr/local/bin";
}


void sushEnv::addToPath(std::string value) {
    env["PATH"] += ":";
    env["PATH"] += value;
}

void sushEnv::setVariable(std::string name, std::string value) {
    env[name] = value;
}

std::string sushEnv::getVariable(std::string name) {
    if(env.find(name) != env.end()) {
        return env[name];
    }
    return "";
}

std::string sushEnv::searchPATH(std::string cmd){
    std::istringstream stream(env["PATH"]);
    std::string tok;
    while(getline(stream,tok,':')){
        tok += "/" + cmd;
        if(sushExec::isExecutable(tok) != -1){
            return tok;
        }
    }

    return "";
}

bool sushEnv::inAlias(std::string alias){
    std::cout << (aliases.find(alias) != aliases.end()) << std::endl;
    return aliases.find(alias) != aliases.end();
}

void sushEnv::setAlias(std::string alias, std::string cmd){
    aliases[alias] = cmd;
}

void sushEnv::setAlias(std::string aliasAndCmd){
    std::istringstream stream(aliasAndCmd);
    std::string alias;
    std::string cmd;
    getline(stream,alias,'=');
    getline(stream,cmd);
    aliases[alias] = cmd;
}

std::string sushEnv::getAlias(std::string alias){
    return aliases[alias];
}