#include "headers/builtin.hpp"

// builtin functions
builtin findBuiltin(std::string cmd){
    if(cmd == "exit"){
        exit();
    }
    return builtin::NONE;
}


void exit(){
    exit(0);
}
