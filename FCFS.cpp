#include<stdio.h>
#include<conio.h>
main()
{

int p,at[10],bt[10],ct[10],tat[10],wt[10],i,totwt=0,tottat=0;
printf("enter the process");
scanf("%d",&p);

printf("\nEnter Process Arival Time\n");
    for(i=1;i<=p;i++)
    {
        printf("P[%d]:",i);
        scanf("%d",&at[i]);
    }



printf("\nEnter Process Burst Time\n");
    for(i=1;i<=p;i++)
    {
        printf("P[%d]:",i);
        scanf("%d",&bt[i]);
    }




ct[1]=at[1]+bt[1];

for(i=2;i<=p;i++)
    {
       if(ct[i-1]>at[i])
       ct[i]=bt[i]+ct[i-1];
       else
       ct[i]=at[i]+bt[i];
    }
for(i=1;i<=p;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        totwt+=wt[i];
        tottat+=tat[i];
       
    }


printf("Process\t AT\t BT\t CT\t TAT\t WT");


for(i=1;i<=p;i++)
{
printf("\n %d\t %d\t %d\t %d\t %d\t %d\n",i,at[i],bt[i],ct[i], tat[i],wt[i]);	
}
printf("\nAverage Waiting time:%f",(float)totwt/p);
printf("\nAverage Turn Around Time:%f",(float)tottat/p);
getch();
}
