#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main ()
{
   pid_t child_pid;
   printf ("the main program process ID is %d\n", (int) getpid());
   printf ("the parent of the main program process ID is %d\n", (int) getppid());
   child_pid = fork () ;
   if (child_pid != 0) {
      printf ("PPP: this is the parent process, with id %d\n", (int) getpid ());
      printf ("PPP: the child's process ID is %d\n",(int) child_pid );
   }
   else
      printf ("CCC: this is the child process, with id %d\n", (int) getpid ());
   printf("@@@@@@@@@@@@Over!@@@@@@@@@@@@@\n");
   return 0;
}
