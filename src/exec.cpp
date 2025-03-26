#include "headers/exec.hpp"

namespace sush {
namespace exec {
pid_t childPid = -1;
sigjmp_buf buf;
void handler(int signum)
{
    if (childPid > 0) {
        printf("\nParent received SIGINT. Killing child process (%d)...\n", childPid);
        kill(childPid, SIGINT);  // Forward SIGINT to the child
        waitpid(childPid, NULL, 0);
        childPid = -1;
        siglongjmp(buf, 1); 
    }
}
int initHandler() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        std::cerr << "Error setting signal handler.\n";
        return 1;
    }
    return 0;
}

//converts the inputed command into two cstyle arrays to be used in execv later on
executableData getExecutableData(std::vector<std::string> args) {
    executableData data;
    data.pathname = (char *) malloc(args[0].size() * sizeof(char));
    std::strcpy(data.pathname, args[0].c_str());
    data.argv = (char**) malloc((args.size() + 1) * sizeof(char *));

    for(size_t i = 0; i < args.size(); i++) {
        data.argv[i] = (char *) malloc(args[i].size() * sizeof(char));
        std::strcpy(data.argv[i], args[i].c_str());
    }
    data.argv[args.size()] = NULL;
    return data;
}

int isExecutable(std::string cmd) {
    //checks if argument exists and isnt a folder
    if(fs::exists(cmd) && fs::is_regular_file(cmd)) {
        //returns true if the file is executable
        return ((fs::status(cmd).permissions() & fs::perms::owner_exec) != fs::perms::none);
    }
    return -1;
}

void execute(executableData& data) {
    switch(childPid = fork()) {
    case 0:
        execv(data.pathname,data.argv);
    default:
        int status;
        waitpid(childPid, &status, 0);
    }
}
};
};
