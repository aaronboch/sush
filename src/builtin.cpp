#include "headers/builtin.hpp"

// builtin functions
/*
builtin findBuiltin(std::string cmd){
    if(cmd == "exit"){
        exit();
    }
    return builtin::NONE;
}
*/
int findBuiltin(std::vector<std::string> args) {
    int ret = -1;
    std::string cmd = args[0];
    if(cmd == "exit") {
        exit();
    }
    else if(cmd == "echo") {
        echo(args);
        ret = 0;
    }
    else if(cmd == "type") {
        type(args);
        ret = 0;
    }

    return ret;
}
//closes the shell
void exit() {
    exit(0);
}

//echoes string following the command
void echo(std::vector<std::string> args) {
    for(size_t i = 1; i < args.size(); i++) {
        std::cout << args[i] << std::endl;
    }
}

//shows what type a file/command is
//types: alias,keyword,function,builtin,file
//implemented types: builtin
void type(std::vector<std::string> args) {
    std::string arg = args[1];
    bool isBuiltin = false;
    if(arg == "exit") {
        isBuiltin = true;
    }
    else if(arg == "echo") {
        isBuiltin = true;

    }
    else if(arg == "type") {
        isBuiltin = true;

    }
    if(isBuiltin) {
        std::cout << arg << " is a shell builtin" << std::endl;
    }
}