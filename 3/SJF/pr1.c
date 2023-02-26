#include<stdio.h>
int main()
{
    int ar[10],bt[10],tp[10];
    int n,c=0,s;
    double wt=0,tat=0;
    printf("\nEnter No. of Processes\n");
    for(int i=0;i<n;i++)
    {
        printf("Arrival Time of :%d",i);
        scanf("%d",&ar[i]);
        printf("Burst Time of :%d",i);
        scanf("%d",&bt[i]);
        tp[i]=bt[i];
    }
    bt[9]=9999;
    for(int t=0;c!=n;t++)
    {
        s=9;
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
    printf("Average Waiting Time:",wt/n);
    printf("Average TAT Time:",tat/n);
    return 0;
}