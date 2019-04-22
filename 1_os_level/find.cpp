//
// Created by pieper on 22-4-19.
//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){


    execl("/usr/bin/find", "ls", ".", NULL);
}


