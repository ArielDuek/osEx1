#include <stdio.h>
#include <stdlib.h>

void print(const char * text )
{
    for (int i = 0; i <20 ; i++)
    {
        printf("process %s\n",text);
        usleep(1000000);
    }
}

int main()
{
    pid_t pid=fork(); //make another process like the parent process,this will be child process

    if(pid==0)
    {
        pid_t pid=fork(); //make another process like the child process,this will be grand child process
        if(pid==0)
        {
            print("grand child");
        }
        else
        {
            print("child");
        }
    }
    
    else
    {
        print("parent");
    }

    return 0;
}
