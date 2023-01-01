#include<stdio.h>
#include <sys/types.h>

int main()
{

int pid,pid1;
pid=fork();

if(pid>0)
{
printf("From parent process\n");
printf("Parent process %d \n",getpid());
}
else
{
sleep(1);

printf("From child process\n");
printf("child process %d \n",getpid());

}
return 0;
}

