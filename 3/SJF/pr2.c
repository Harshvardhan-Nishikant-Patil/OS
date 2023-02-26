#include<stdio.h>
int main()
{
    int n; 
    printf("\nEnter No. of Processes\n");
    scanf("%d",&n);
    int ar[100],bt[100],tp[100];
    int c=0,t;
    double wt=0,tat=0;
    printf("\nEnter Process Details\n");
    for(int i=0;i<n;i++)
    {
        printf("Arrival Time:%d",i);
        scanf("%d",&ar[i]);
        printf("Burst Time:%d",i);
        scanf("%d",&bt[i]);
        tp[i]=bt[i];
    }
    bt[99]=9999;
    for(int t=0;c!=n;t++)
    {
        int s=99;
        for(int i=0;i<n;i++)
        {
            if(ar[i]<=t && bt[i]<bt[s] && bt[i]>0)
            {
                s=i;
            }
        }
        bt[s]--;
        if(bt[s]==0)
        {
            c++;
            int e=t+1;
            wt=wt+e-ar[s]-tp[s];
            tat=tat+e-ar[s];
        }
    }
        printf("Average Waiting time:%f\n",wt/n);
        printf("Average TAT time:\n%f",tat/n);
        return 0;
}