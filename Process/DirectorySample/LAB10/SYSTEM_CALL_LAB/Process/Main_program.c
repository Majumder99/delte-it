#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  
  int status;
   printf("main app\n");

   
   int a = fork();
   
   char *name[]={"Helper_program","HELLO",NULL};
   
   
   if(a==0)
   {
 
     execvp("./Helper_program",name);
  }
  
  wait(&status);
  printf("%d\n",WEXITSTATUS(status));
  return 0;
}
