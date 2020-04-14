#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main()
{
    pid_t pid=fork(); //make another process like the parent process,this will be child process

    if(pid==0)
    {
        //make a root dir
        chdir("/");

        //change the session
        setsid();

        printf("daemon start now\n");

        //close all input and output Channels
        close(stdout);
        close(stdin);
        close(stderr);

        //open log
        openlog("Daemon",LOG_PID,LOG_DAEMON);
        syslog(LOG_NOTICE,"daemon started");
        usleep(3000);
        syslog(LOG_NOTICE,"daemon working");
        usleep(3000);
        syslog(LOG_NOTICE,"daemon finished");

    }
    else
    {
        printf("The daemon PID is %d\n",pid);
    }

    return 0;
}


