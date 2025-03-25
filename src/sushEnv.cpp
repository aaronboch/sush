
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
        if(sushExec::isExecutable(tok)){
            return tok;
        }
    }

    return "";
}
