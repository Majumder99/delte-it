#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  
   int a = fork();
   
   char *name[]={"ls","-l",NULL};
   
   
   if(a==0)
   {
 
     execvp("ls",name);
  }
  
  return 0;
}
