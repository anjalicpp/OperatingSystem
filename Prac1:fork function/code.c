#include<stdio.h>
#include<unistd.h>
int main()
{
  fork();
  printf("%d",getpid());
  printf("\n");
}

FORK();
 1. Fork is a system call to create a new process from an existing running process.
 2. The new process is called child process of calling new parent process.
 3. Child process runs concurrently with parent process.
 4. It returns three values :zero,negative,positive.
   4a.Zero:Returned to the newly created child process
   4b.Negative:creation of child process was unsuccesful.
   4c.Postive:returned to parent process and value contains process id of newly created child process.
5.total no of proceses created is =2^n where n is no of times fork();is called.
   
