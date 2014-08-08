#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
sig_atomic_t child_exit_status;
void clean_up_child_process (int signal_number)
{
   /* Clean up the child process. */
   int status;
   wait (&status);
   /* Store its exit status in a global variable. */
   child_exit_status = status;
   printf("\nSIGCHLD signal catched and handled.\n");
}
int main ()
{
   /* Handle SIGCHLD by calling clean_up_child_process. */
   struct sigaction sigchld_action;
   memset (&sigchld_action, 0, sizeof (sigchld_action));
   sigchld_action.sa_handler = &clean_up_child_process;
   sigaction (SIGCHLD, &sigchld_action, NULL);
   /* Now do things, including forking a child process. */
   pid_t child_pid;
   /* Create a child process. */
   child_pid = fork ();
   if (child_pid > 0) {
      /* This is the parent process. Sleep for a minute. */
      sleep (100);
      sleep (10);
      printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
   }
   else {
      /* This is the child process. Exit immediately. */
      printf("\nChild process started!\n");
      printf("\nChild process ended!\n");
      exit (0);
   }
   return 0;
}
