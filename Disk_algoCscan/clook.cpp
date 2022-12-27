#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
int req,head,seektime=0,dir,size;

printf("Enter the number of req:");
scanf("%d",&req);

int rq[req];

printf("Enter the content of request queue:");
for(int i=0;i<req;i++)
{
    scanf("%d",&rq[i]);
}

printf("Enter the initial position of read write head:");
scanf("%d",&head);

printf("Enter the disk size:");
scanf("%d",&size);

printf("Enter the direction of movement high 1 or low 0");
scanf("%d",&dir);

for(int i=0;i<req;i++)
{
    for(int j=0;j<req-1-i;j++)
    {
        if(rq[j]>rq[j+1])
        {
            int temp;
            temp=rq[j];
            rq[j]=rq[j+1];
            rq[j+1]=temp;
        }
    }
}

int index;
for(int i=0;i<req;i++)
{
    if(head<rq[i])
    {
        index=i;
        break;
    }
}

if(dir==1)
{
    for(int i=index;i<req;i++)
    {
        seektime+=abs(rq[i]-head);
        head=rq[i];
    }
    for(int i=index-1;i>=0;i--)
    {
        seektime+=abs(rq[i]-head);
        head=rq[i];
    }
}

else
{
    for(int i=index-1;i>=0;i--)
    {
        seektime+=abs(rq[i]-head);
        head=rq[i];
    }
    for(int i=index+1;i<req;i++)
    {
        seektime+=abs(rq[i]-head);
        head=rq[i];
    }
}
printf("Total Seektime:%d",seektime);
}
