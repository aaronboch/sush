#include "headers/builtin.hpp"


namespace sush {

namespace builtin {

int find(std::vector<std::string>& args, sush::history& hstr, sush::env& env) {
    int ret = -1;
    std::string cmd = args[0];
    if(cmd == "exit") {
        exit();
    }
    else if(cmd == "echo") {
        echo(args,env);
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
    } else if(cmd == "alias") { //example: alias ""
        alias(args,env);
        ret = 0;
    } else if(cmd == "export") {
        exprt(args,env);
        ret = 0;
    }

    return ret;
}
//closes the shell
void exit() {
    std::exit(0);
}

//echoes string following the command
void echo(std::vector<std::string>& args, sush::env env) {
    size_t pos;
    for(size_t i = 1; i < args.size(); i++) {
        //if the string contains a $ try to echo the environment variable, of the name following the $
        // -> echo $PATH echoes the PATH variable
        if((pos = args[i].find('$')) != std::string::npos) {
            //escapes $ when \ is used before
            if(pos > 0 && args[i][pos-1] == '\\') {
                args[i] = args[i].substr(pos);
            }
            else {
                args[i] = env.getVariable(args[i].substr(pos+1));
            }
        }
        std::cout << args[i] << std::endl;
    }
}

//shows what type a file/command is
//types: alias,keyword,function,builtin,file
//implemented types: builtin
void type(std::vector<std::string>& args) {
    if(args.size() < 2) {
        std::cout << "type: Could not find ''" << std::endl;
    } else {
        std::string arg = args[1];

        if(isBuiltin(arg)) {
            std::cout << arg << " is a shell builtin" << std::endl;
        }
        else {
            std::cout << "type: Could not find '" << arg << "'" << std::endl;
        }
    }
}

bool isBuiltin(std::string arg) {
    if(arg == "exit" || arg == "echo" || arg == "type" || arg == "pwd" || arg == "cd" || arg == "history" || arg == "alias" || arg == "export") {
        return true;
    }
    return false;
}

void pwd() {
    try {
        std::cout <<  fs::current_path()  << std::endl;
    } catch(const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void cd(std::vector<std::string>& args) {
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

void history(sush::history& hstr) {
    hstr.printHistory();
}
// makes/changes alias or if called without second argument, prints out all aliases
void alias(std::vector<std::string>& args, sush::env& env) {
    if(args.size() < 2) {
        env.printAliases();
        return;
    }
    //put everything after the alias cmd into one string
    if(args.size() > 2) {
        for(size_t i = 2; i < args.size(); i++) {
            args[1] += " " + args[i];
        }
    }
    env.setAlias(args[1]);
}

// makes/changes environment variable or if called without second argument, prints out all environment variables
void exprt(std::vector<std::string>& args, sush::env& env) {
    if(args.size() < 2) {
        env.printEnvr();
        return;
    }
    if(args.size() > 2) {
        for(size_t i = 2; i < args.size(); i++) {
            args[1] += " " + args[i];
        }
    }
    env.setVariable(args[1]);
}

};
};