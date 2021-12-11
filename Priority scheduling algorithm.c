#include<stdio.h>
#include<conio.h>
int main()
{
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
double avg_wt,avg_tat;
printf("Enter Number of Process:");
scanf("%d",&n);
printf("\nEnter the Process No, Burst Time and Priority\n");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
scanf("%d",&pr[i]);
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(pr[j]<pr[pos])
pos=j;
}
temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
avg_wt=(total)/(n);
int t1 = total;
total=0;
printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\n%d\t\t %d\t\t %d\t\t %d",p[i],bt[i],wt[i],tat[i]);
}
avg_tat=(total)/(n);
printf("\n\nTotal Waiting Time is:%d",t1);
printf("\nTotal Turnaround Time is:%d",total);
printf("\nThe Average Waiting Time is:%f",avg_wt);
printf("\nThe Average Turnaround Time is:%f",avg_tat);
return 0;
}


