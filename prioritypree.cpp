#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,burst[n],rem[n],pri[n];
	printf("Enter number of Processes:");
	scanf("%d",&n);
	int arr[n],sum=0;
	printf("Enter the cpu burst of process");
	for(int i=0;i<n;i++){
	scanf("%d",&burst[i]);
	sum+=burst[i];
	}
	printf("Enter the arrival time of process");
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter the priority of the process");
	for(int i=0;i<n;i++)
	scanf("%d",&pri[i]);
	int pos,i;
	int min;
	int waits=0,trys=0,prev,wait[n],vis[n]={0},exe[n];pos;
	for(int i=0;i<n;i++)
	wait[i]=-1;
	for(int i=0;i<sum;i++){
		min=10000000;
		for(int j=0;j<n;j++){
			if(arr[j]<=i&&burst[j]>0&&pri[j]<min){
			min=pri[j];
			pos=j;
			}
		}
	
		if(wait[pos]==-1)
		wait[pos]=i-arr[pos];
		else
		wait[pos]+=i-exe[pos];
		burst[pos]--;
		exe[pos]=i+1;
	}
	printf("waiting time \n");
	sum=0;
	for(int i=0;i<n;i++){
	printf("%d ",wait[i]);
	sum+=wait[i];}
	printf("average waiting time:%lf\n",sum/(n*1.0));
}
