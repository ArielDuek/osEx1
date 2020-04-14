#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

#define ARR_SIZE 10000
#define CYCLES 10000

char children_arr[10000+1];

void print(char * text )
{
    for (int i = 0; i <CYCLES ; i++)
    {
        printf("process %s \n",text);
        usleep(1000000);
    }
}

int cloneFunc(void* input)
{
    char * args[]={"./task2.2",NULL};
    execvp(args[0],args); //make task2.2 s an independent process
}

int daemonFunc(void* input)
{
    char * args[]={"./task2.3",NULL};
    execvp(args[0],args); //make task2.3 s an independent process
}

int main()
{
    pid_t pid=fork(); //Turns on task2.1
    printf("PID is: %d ",pid);
    if(pid==0)
    {
        char * args[]={"./task2.1",NULL};
        int res1=clone(cloneFunc,children_arr+ARR_SIZE,CLONE_PARENT,0); //Turns on task2.2
        execvp(args[0],args); //make task2.1 s an independent process
    }
    else
    {
        int res2=clone(daemonFunc,children_arr+ARR_SIZE,CLONE_PARENT,0); //Turns on task2.3
        print("parent");
    }

    return 0;
}

