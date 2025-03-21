#include "headers/builtin.hpp"
#include "headers/sushHistory.hpp"

// builtin functions
/*
builtin findBuiltin(std::string cmd){
    if(cmd == "exit"){
        exit();
    }
    return builtin::NONE;
}
*/
int findBuiltin(std::vector<std::string> args, sushHistory hstr) {
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
    } else if(cmd == "pwd") {
        pwd();
        ret = 0;
    } else if(cmd == "cd") {
        cd(args);
        ret = 0;
    } else if(cmd == "history") {
        history(hstr);
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
    if(args.size() < 2) {
        std::cout << "type: Could not find ''" << std::endl;
    } else {
        std::string arg = args[1];
        bool isBuiltin = false;
        if(arg == "exit" || arg == "echo" || arg == "type" || arg == "pwd" || arg == "cd" || arg == "history") {
            isBuiltin = true;
        }

        if(isBuiltin) {
            std::cout << arg << " is a shell builtin" << std::endl;
        }
        else {
            std::cout << "type: Could not find '" << arg << "'" << std::endl;
        }
    }
}


void pwd() {
    try {
        std::cout <<  fs::current_path()  << std::endl;
    } catch(const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void cd(std::vector<std::string> args) {
    if(args.size() == 1) {
        fs::current_path("/home");
    } else {
        std::string arg = args[1];
        try {
            fs::current_path(arg);
        } catch(const std::filesystem::filesystem_error& e) {
            std::cout << "The directory \"" << arg << "\" does not exist" << std::endl;
        }
    }
}

void history(sushHistory hstr) {
    hstr.printHistory();
    
}

