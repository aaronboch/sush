#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(){
    std::string input = nullptr;    
    std::vector<std::string> args;
    int status = 0;

    while(true){
        std::cout<< "> " << std::flush;
        //Read input
        std::cin >> input;
        
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
        args.push_back(arg);
    }
    return;
}

int sushExec(std::vector<std::string> args){
    return 0;
}