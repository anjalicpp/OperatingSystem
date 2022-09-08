Write a program to create a child process in parallel to main process .Define an array of numbers .The child process has to calculate sum of even number
and parent  process has to calculate sum of odd numbers.

#include<stdio.h>
#include<unistd.h>    //Header file for getpid(); function
int main()
{int n;
printf("Enter the size of arrray");
scanf("%d",&n);
int arr[n];

printf("Enter elements in array");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
int x=fork();//returns 3types of values
if(x>0)
{
for(int i=0;i<n;i++)
{
  if(arr[i]%2==0)
  esum+=arr[i];
}
printf("The evensum is :%d",esum);
printf("The process Id is+ %d",getpid());
}
printf("\n");
else{
for(int i=0;i<n;i++)
{
if(arr[i]%2==1)
osum+=arr[i];
}
printf("The osum is:%d",osum);
printf("The process Id=%d",getpid());
}
printf("\n");
return 0;
}

Fork:system call to create new process.
getpid():returns process id of the patent calling the process.This function has no parameter to be passed ie,void
