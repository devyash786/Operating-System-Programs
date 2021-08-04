#include<stdio.h>
#include<stdlib.h>
int main()
{
	int Arrival[10],Burst[10],priority[10],ready[10],n,i,j,sum=0;
	double av1=0,av2=0;
	printf("Enter number of Processes:");
	scanf("%d",&n);
    printf("Enter Burst Time,Arrival Time & Priority");
    for(i=0;i<n;i++)
    {
    	printf("\nEnter burst Time of P%d::",i+1);
    	scanf("%d",&Burst[i]);
    	printf("\nEnter Arrival Time of P%d::",i+1);
    	scanf("%d",&Arrival[i]);
    	printf("\nEnter Priority of P%d::",i+1);
    	scanf("%d",&priority[i]);
    	//process[i]=i+1;
    	sum=sum+Burst[i];
    	
    }
    int tat[n],wt[n],arrt=0,vis[n]={0};
    while(arrt<sum)
    {
    	 int min=10000,count;
    	 for(j=0;j<n;j++){
		 
    	 if(Arrival[j]<=arrt && priority[j]<min && vis[j]==0) 
		  {
		  	count=j;
		  	min=priority[j];
		  }
	}
	vis[count]=1;
	wt[count]=arrt;
	arrt+=Burst[count];
   }

   printf("\nWaiting Time:\n");
   for(i=0;i<n;i++)
   {
   	printf("%d  ",wt[i]-Arrival[i]);
   	av1+=wt[i]-Arrival[i];
   }
   printf("\nTurn around Time:\n");
   for(i=0;i<n;i++)
   {
   	printf("%d  ",wt[i]-Arrival[i]+Burst[i]);
   	av2=av2+wt[i]-Arrival[i]+Burst[i];
   }
   printf("\nAverage Waiting Time is %lf \n TAT is %lf",av1/n,av2/n);
}
