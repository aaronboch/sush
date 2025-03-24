#ifndef COMMON_H
#define COMMON_H
#include "headers/common.hpp"
#endif

#define SUSH_HISTORY_SIZE 100
#include "headers/builtin.hpp"
#include "headers/sushHistory.hpp"
#include "headers/exec.hpp"


std::vector<std::string> sushParse(std::string input);
int sushExec(std::vector<std::string> args, sushHistory hstr);

int main() {
    
    sushHistory hstr{};

    std::string input;
    std::vector<std::string> args;
    int status = 0;
    
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
        status = sushExec(args,hstr);
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

int sushExec(std::vector<std::string> args, sushHistory hstr) {
    bool found = false;
    
    if(findBuiltin(args,hstr) != -1 && found == false) {
        found = true;
    }  
    else if (found == false && exec::isExecutable(args) != -1){
        exec::executableData data = exec::getExecutableData(args);
        
        pid_t pid = 0;
        switch(pid = fork()){
            case 0:
                execv(data.pathname,data.argv);
            default:
                int status;
                waitpid(pid, &status, 0);
        }
        found = true;
    }

    if(!found){
        std::cout << args[0] << ": command not found" << std::endl;
    }
    return 0;
}