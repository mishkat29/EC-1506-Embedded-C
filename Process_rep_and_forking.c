#include <sys/types.h>
#include <studio.h>
#include <unistd.h>

task_struct
pid t pid; /* process identifier */
long state; /* state of the process */
unsigned int time slice /* scheduling information */
struct task struct *parent; /*this process’s parent */
struct list head children; /* this process’s children */
struct files struct *files; /* list of open files */
struct mm struct *mm; /*address space of this pro */

int main()
{
pid_t pid;
/* fork another process */
pid = fork();
if (pid < 0) { /* error occurred */
fprintf(stderr, "Fork Failed");
return 1;
}
else if (pid == 0) { /* child process */
execlp("/bin/ls", "ls", NULL);
}
else { /* parent process */
/* parent will wait for the child */
wait (NULL);
printf ("Child Complete");
}
return 0;
