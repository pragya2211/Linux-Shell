#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include "myshell_ls.c"
#include "myshell_cat.c"
#include "myshell_date.c"
#include "myshell_mkdir.c"
#include "myshell_rm.c"
#define MEM 1024
char* history[100];
char *in,*in1;
char* list[MEM]; 
int count = 0;
void getInput()
{
    size_t buffer_mem = 0;
    getline(&in,&buffer_mem,stdin);
    in1 = malloc(strlen(in) * sizeof(char));
    strncpy(in1,in,strlen(in));
    count = 0;
    while((list[count] = strsep(&in, " \t\n")) != NULL && count < MEM-1)
    {
        if(sizeof(list[count])==0)
        {
            free(list[count]);
        }
        else count++;  
    }
}
void execute(int st,int st1)
{
    if(strcmp(list[0],"pwd") == 0) 
    {
        char tem[1000];
        char* path=getcwd(tem, sizeof(tem));
        if(path != NULL)
        {
            printf("%s\n",tem);
        }
    }
    else if(strcmp(list[0],"ls") == 0)
    {
           imp_ls(list);
    }
    else if(strcmp(list[0],"history") == 0)
    {
        int d = 0;
        while(history[d] != NULL)
        {
            int i =0;
            printf("%s",history[d]);
            printf("\n");
            d++;   
        }
    } 
    else if(strcmp(list[0],"echo") == 0)
    {
            if(strcmp(list[1],"*") == 0)
            {
                struct dirent **num_list;
                int num = scandir(".", &num_list, 0, alphasort);
                if(num > 0)
                {
                    for(int i =0;i<num;i++)
                    {
                        if(strcmp(num_list[i]->d_name,".") == 0|| strcmp(num_list[i]->d_name,"..") == 0)
                        {
                            continue;
                        }
                        else printf("%s%s",num_list[i]->d_name," ");
                    }
                }
            }
            else if(strcmp(list[1],"-E") == 0)
            {
                int i = 2;
                while(list[i] != NULL)
                {
                    printf("%s" ,list[i]);
                    i++;
                }
            }
            else
            {
                int i = 1;
                while(list[i] != NULL)
                {
                    printf("%s " , list[i]);
                    i++;
                }
            }
    }
    else if(strcmp(list[0],"mkdir")==0)
    {
        imp_mkdir(list);
    }
    else if(strcmp(list[0],"cd")==0)
    {
        chdir(list[1]);
    }
    else if(strcmp(list[0],"cat")==0)
    {
        imp_cat(list);
    }
    else if(strcmp(list[0],"date") == 0)
    {
        imp_date(list);  
    }
    else if(strcmp(list[0],"rm") == 0)
    {
       imp_rm(list); 
    }
    else
    {
        if(strcmp(list[0],"exit") == 0)
        {
            printf("You are exiting\n");
        }
        else
        {
            printf("Please enter a valid command\n");
        }
    }  
}
static int n = 0;
int main()
{
    int abc = 0;
    int mem = MEM;
    int status = 0;
    *list = (char*)malloc(mem);
    printf("\n");
    while(strcmp(*list,"exit")!= 0)
    {
        char tem[1000];
        char* path=getcwd(tem, sizeof(tem));
        printf("%s/myshell$ " ,path);
        getInput();
        history[abc] = *list;
        abc++;
        int st = 1;
        char* next;
        next = malloc(mem);
        next = strchr(*list,'|');
        while(next != NULL)
        {
            *next = '\0';
            execute(st,0);
            *list = next+1;
            next = strchr(*list,'|');
            st = 0;
            printf("\n");
        }
        execute(st,1);
        n= 0;
    }
}