#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#define MEM 1024
//char* list[MEM]; 
void imp_ls(char* list[MEM])
{
    if(list[1] != NULL)
    {
        if(strcmp(list[1],"-l") == 0)
        {
            int ret;
            pid_t child_pid = fork();
            if(child_pid == 0)
            {
                ret = execl("/bin/ls", "ls","-1", (char *)0);
            }
            else
            {
                waitpid(child_pid,0,WUNTRACED);
            }
        }
        else if(strcmp(list[1],"-lh") == 0)
        {
            int ret;
            pid_t child_pid = fork();
            if(child_pid == 0)
            {
                ret = execl("/bin/ls", "ls","-lh", (char *)0);
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
                ret = execl("/bin/ls", "ls",NULL, (char *)0);
            }
            else
            {
                waitpid(child_pid,0,WUNTRACED);
            }   
        }   
    }
}
