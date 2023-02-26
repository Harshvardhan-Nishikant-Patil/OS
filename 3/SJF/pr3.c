#include<stdio.h>
int main()
{
    int n,at[100],bt[100],tp[100],c=0;
    double wt=0,tat=0;
    printf("Enter The no. of Processes\n");
    scanf("%d",&n);
    printf("Enter Process Details:\n");
    for(int i=0;i<n;i++)
    {
        printf("Arrival Time:%d:",i);
        scanf("%d",&at[i]);
        printf("Burst Time:%d:",i);
        scanf("%d",&bt[i]);
        tp[i]=bt[i];
    }
    bt[99]=9999;
    for(int t=0;c!=n;t++)
    {
        int s=99;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=t && bt[i]<bt[s] && bt[i]>0)
            {
                s=i;
            }
        }
        bt[s]--;
        if(bt[s]==0)
        {
            c++;
            int e=t+1;
            wt=wt+e-at[s]-tp[s];
            tat=tat+e+-at[s];      
           
         }
          printf("\np%d\t\t  %d\t\t    %f\t\t\t%f",s,bt[s],wt,tat) ; 
    }
    printf("\nAverage Waiting Time:%f",wt/n);
    printf("\nAverage TAT:%f",tat/n);
}