#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  
  int status;
  //printf("%d",status);
   printf("main app\n");
   
   int a = fork();
   
   char *name[]={"ls","/bin",NULL};
   
   
   if(a==0)
   {
     
     execvp("/bin/ls",name);
     //exit(5);
  }
  
  wait(&status);
  printf("%d\n",WEXITSTATUS(status));
  return 0;
}
