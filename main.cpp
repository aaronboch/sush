#include <iostream>
#include <string>
#include <memory>

int main(){
    std::string input = nullptr;    
    std::shared_ptr<std::string> args = nullptr;
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


std::shared_ptr<std::string> sushParse(std::string input){
    return nullptr;
}

int sushExec(std::shared_ptr<std::string> args){
    return 0;
}