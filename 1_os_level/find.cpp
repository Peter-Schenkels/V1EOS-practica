//
// Created by pieper on 22-4-19.
//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <iostream>
#include <fcntl.h>


int main(){
    int fd, nread;
    char pc[512];

    if ((fd = open("homer.txt", O_RDONLY)) == -1){
        std::cout << "Error\n";

    }

    if(fd < 0) {
        return 1;
    }
    read(fd, pc, 1);

    std::string prompt = pc;

    std::cout << prompt;


}


