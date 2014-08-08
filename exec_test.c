#include <unistd.h>
#include <stdio.h>
int main()
{
   printf("main function started to excute.\n");
   char* arg_list[] = {
      "ls", /* argv[0], the name of the program. */
      "-l",
      "/",
      NULL /* The argument list must end with a NULL. */
   };
   int status = execlp("ls",arg_list);
   printf("Over!\n");
   return 0;
}
