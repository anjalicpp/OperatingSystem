#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
   int p,r,i,j,k,flag,cnt=0;
   printf("Enter the total number of process:");
   scanf("%d",&p);

   printf("Enter the total number of resources:");
   scanf("%d",&r);

   int allocated[p][r],maxneed[p][r],remneed[p][r],available[r],seq[p],f[p];

   printf("Enter the allocated matrix:");
   for(i=0;i<p;i++)
   {
    for(j=0;j<r;j++)
   {
    scanf("%d",&allocated[i][j]);     
   }
   }

   printf("Enter the Max Need matrix:");
   for(i=0;i<p;i++)
   {
    for(j=0;j<r;j++)
   {
    scanf("%d",&maxneed[i][j]);     
   }
   }

   printf("Enter the available matrix:");
   for(j=0;j<r;j++){scanf("%d",&available[j]);}

   for(i=0;i<p;i++)
   {
    for(j=0;j<r;j++)
   {
    remneed[i][j]=maxneed[i][j]-allocated[i][j];    
   }
   }

   for(i=0;i<p;i++){f[i]=0;}

   for(k=0;k<p;k++){
    for(i=0;i<p;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            for(j=0;j<r;j++)
            {
            if(available[j]<remneed[i][j])
            {
                flag=1;
                break;
            }
            }
            if(flag==0)
            {
            seq[cnt++]=i;
            for(int t=0;t<r;t++){available[t]+=allocated[i][t];}
            f[i]=1;
            }
        }
   }
 }
 flag=1;
 for(i=0;i<p;i++)
 {
    if(f[p]==0)
    {
    flag=0;
    printf("Not a Safe Sequence");
    break;
    }
 }
 if(flag==1)
 {printf("Safe Sequence\n");
 printf("Process Execution Sequence:");
 for(i=0;i<p;i++)
 {printf("%d\t",seq[i]+1);}
 }
 return 0;
}
 
