#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void main()
{

pid_t pid;
int a = fork();
pid = getpid();

if(a == -1)
printf("\n Error in creating process ");

else if(a == 0)
printf("\nExecuting in child process, pid=%d and its parent pid = %d ",getpid(),getppid());

else
printf("\nExecuting in parent process,pid=%d \n",getpid());
}

