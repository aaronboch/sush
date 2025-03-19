#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> sushParse(std::string input);
int sushExec(std::vector<std::string> args);

int main(){
    std::string input;    
    std::vector<std::string> args;
    int status = 0;

    while(true){
        std::cout<< "> " << std::flush;
        //Read input
        std::getline(std::cin, input);
        //Parse input
        args = sushParse(input);
        //Execute arguments
        status = sushExec(args);
        
    }

    return 0;
}

std::vector<std::string> sushParse(std::string input){
    std::vector<std::string> args;
    std::stringstream inputStream(input);
    std::string arg;
    while(std::getline(inputStream,arg,' ')){
        if (!arg.empty()) {
            args.push_back(arg);
        }
    }
    return args;
}

int sushExec(std::vector<std::string> args){
    std::cout << args[0] << ": command not found" << std::endl;




    return 0;
}