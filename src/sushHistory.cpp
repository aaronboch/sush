#include "headers/sushHistory.hpp"


sushHistory::sushHistory(){
     historyFile.open(".sush_history", std::ios::app);
     if (!historyFile) {
        std::cerr << "Failed to open history file." << std::endl;
    }
}

sushHistory::~sushHistory(){
    if(historyFile.is_open()){
        historyFile.close();
    }
}

sushHistory::sushHistory(sushHistory& hstr) {
    if (hstr.historyFile.is_open()) {
        historyFile.open(".sush_history", std::ios::app);
    }
}

int sushHistory::count(){
    std::fstream temp{".sush_history"};
    std::string l;
    int numlines = 0;
    while(getline(temp,l)){
        numlines++;
    }
    temp.close();
    return numlines;
}
void sushHistory::write(std::string input){
    if (historyFile.is_open()) {
        historyFile << input << std::endl;
    } else {
        std::cerr << "Failed to write to history file!" << std::endl;
    }
}

void sushHistory::deleteLine(){
    historyFile.close();

    std::ofstream newHis{".sush_history_new"};
    std::fstream oldHis{".sush_history"};
    std::string l;


    bool first = true;
    while(getline(oldHis,l)){
        if(first){
            first = false;
        }else{
            newHis << l << std::endl;
        }
    }
    
    
    newHis.close();
    oldHis.close();
    
    remove(".sush_history");
    
    rename(".sush_history_new",".sush_history");
    std::fstream temp{".sush_history"};
    
    historyFile.open(".sush_history", std::ios::app);
}

void sushHistory::printHistory(){
    std::fstream temp{".sush_history"};
    std::string l;
    while(getline(temp,l)){
        std::cout << l << std::endl;
    }
    temp.close();
}