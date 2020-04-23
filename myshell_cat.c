#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include<fcntl.h>
#define MEM 1024
void imp_cat(char* list[MEM])
{
    if(strcmp(list[1]," ") != 0)
    {
       int ret;
        pid_t child_pid = fork();
        if(child_pid == 0)
        {
            ret = execl("/bin/cat", "cat", list[1],list[2], (char *)0);
        }
        else
        {
            waitpid(child_pid,0,WUNTRACED);
        } 
    }
    else
    {
      int ret;
        pid_t child_pid = fork();
        if(child_pid == 0)
        {
            ret = execl("/bin/cat", "cat", list[1], (char *)0);
        }
        else
        {
            waitpid(child_pid,0,WUNTRACED);
        }  
    }
       
}