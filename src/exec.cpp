#include "headers/exec.hpp"
namespace exec {
executableData getExecutableData(std::vector<std::string> args) {

    executableData data;
    data.pathname = (char *) malloc(args[0].size() * sizeof(char));
    std::strcpy(data.pathname, args[0].c_str());
    data.argv = (char**) malloc(args.size() * sizeof(char *));
    data.argvSize = args.size();

    for(size_t i = 0; i < args.size(); i++) {
        data.argv[i] = (char *) malloc(args[i].size() * sizeof(char));
        std::strcpy(data.argv[i], args[i].c_str());
    }
    return data;
}

int isExecutable(std::vector<std::string> args) {
    if(args.size() < 1) {
        return -1;
    }
    std::string cmd = args[0];
    //checks if argument exists and isnt a folder
    if(fs::exists(cmd) && fs::is_regular_file(cmd)) {
        //returns true if the file is executable
        return ((fs::status(cmd).permissions() & fs::perms::owner_exec) != fs::perms::none);
    }

    return -1;
}
};