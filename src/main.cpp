#ifndef COMMON_H
#define COMMON_H
#include "headers/common.hpp"
#endif

#define SUSH_HISTORY_SIZE 100
#include "headers/builtin.hpp"
#include "headers/history.hpp"
#include "headers/exec.hpp"
#include "headers/env.hpp"

std::vector<std::string> sushParse(std::string input);
int sushExecute(std::vector<std::string> args, sush::history& hstr, sush::env& env);

int main() {
    if(sush::exec::initHandler()){
        return -1;
    }

    sush::history hstr{};
    sush::env env{};

    std::string input;
    std::vector<std::string> args;
    if (sigsetjmp(sush::exec::buf, 1) == 0) {
        printf("Press Ctrl+C to trigger SIGINT\n");
    } else {
        printf("Returned to main via longjmp\n");
    }
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

int sushExecute(std::vector<std::string> args, sush::history& hstr, sush::env& env) {
    bool found = false;
    std::string cmd = args[0];
    //search builtins
    if(sush::builtin::find(args,hstr,env) != -1) {
        found = true;
    }  else if(env.inAlias(args[0])){ //search alias
        std::string newCmd = env.getAlias(args[0]);
        args = sushParse(newCmd);
        sushExecute(args,hstr,env);
        found = true;
    }//search given direct path
    else if (sush::exec::isExecutable(cmd) != -1){
        sush::exec::executableData data = sush::exec::getExecutableData(args);
        sush::exec::execute(data);
        found = true;
    } //search with PATH env variable
    else{
        std::string newPath = env.searchPATH(cmd);

        if(!newPath.empty()){
            args[0] = newPath;
            sush::exec::executableData data = sush::exec::getExecutableData(args);
            sush::exec::execute(data);
            found = true;
        }
    }
    if(!found){
        std::cout << cmd << ": command not found" << std::endl;
    }
    return 0;
}