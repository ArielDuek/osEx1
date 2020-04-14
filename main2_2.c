#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

#define ARR_SIZE 10000
#define CYCLES 10000

char children_arr[ARR_SIZE+1];

void print(char * text )
{
    for (int i = 0; i <CYCLES ; i++)
    {
        printf("process %s \n",text);
        usleep(1000000);
    }
}

int child1()
{
    print("child one thread");
}

int child2()
{
    print("child two thread");
}


int main()
{
    int res1=clone(child1,children_arr+ARR_SIZE,CLONE_PARENT,0);
    int res2=clone(child2,children_arr+ARR_SIZE,CLONE_PARENT,0);
    printf("clone res1 = %d\n",res1);
    printf("clone res2 = %d\n",res2);
    print("parent");
    return 0;
}

