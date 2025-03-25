#ifndef COMMON_H
#define COMMON_H
#include "headers/common.hpp"
#endif

#define SUSH_HISTORY_SIZE 100
#include "headers/builtin.hpp"
#include "headers/sushHistory.hpp"
#include "headers/exec.hpp"
#include "headers/sushEnv.hpp"


std::vector<std::string> sushParse(std::string input);
int sushExecute(std::vector<std::string> args, sushHistory& hstr, sushEnv& env);

int main() {
    
    sushHistory hstr{};
    sushEnv env{};

    std::string input;
    std::vector<std::string> args;
    
    while(true) {

        std::string cwd = fs::current_path();
        std::cout<< cwd << "> " << std::flush;
        //Read input
        std::getline(std::cin, input);
        if(input == ""){
            continue;
        }
        if(hstr.count() >= HISTORY_MAX_LENGTH){
            hstr.deleteLine();
        }   
        hstr.write(input);

        //Parse input
        args = sushParse(input);
        //Execute arguments
        sushExecute(args,hstr,env);
    }
    
    return 0;
}

std::vector<std::string> sushParse(std::string input) {
    std::vector<std::string> args;
    std::stringstream inputStream(input);
    std::string arg;
    while(std::getline(inputStream,arg,' ')) {
        if (!arg.empty()) {
            args.push_back(arg);
        }
    }
    return args;
}

int sushExecute(std::vector<std::string> args, sushHistory& hstr, sushEnv& env) {
    bool found = false;
    std::string cmd = args[0];
    //search builtins
    if(findBuiltin(args,hstr,env) != -1) {
        found = true;
    }  else if(env.inAlias(args[0])){ //search alias
        std::string newCmd = env.getAlias(args[0]);
        args = sushParse(newCmd);
        sushExecute(args,hstr,env);
        found = true;
    }//search given direct path
    else if (sushExec::isExecutable(cmd) != -1){
        sushExec::executableData data = sushExec::getExecutableData(args);
        sushExec::execute(data);
        found = true;
    } //search with PATH env variable
    else{
        std::string newPath = env.searchPATH(cmd);

        if(!newPath.empty()){
            args[0] = newPath;
            sushExec::executableData data = sushExec::getExecutableData(args);
            sushExec::execute(data);
            found = true;
        }
    }
    if(!found){
        std::cout << cmd << ": command not found" << std::endl;
    }
    return 0;
}