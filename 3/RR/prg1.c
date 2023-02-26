#include<stdio.h>
int main()
{
    int n,q,ar[100],bt[100],tp[100],c,f=0,r,t,i;
    double wt=0,tat=0;
    printf("\nEnter No. of Processes\n");
    scanf("%d",&n);
    r=n;
    printf("Enter Process Details:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nArrival Time : %d : ",i);
        scanf("%d",&ar[i]);
        printf("\nBurst Time : %d : ",i);
        scanf("%d",&bt[i]);
        tp[i]=bt[i];
    }
    printf("\nEnter Time Quantum\n");
    scanf("%d",q);
    for(t=0,i=0;r!=0;)
    {
        if(tp[i]<=q && tp[i]>0)
        {
            t+=tp[i];
            tp[i]=0;
            f=1;
        }
        else if(tp[i]>0)
        {
            tp[i]-=q;
            t=t+q;
        }
        if(tp[i]==0 && f==1)
        {
            r--;
            printf("P[%d]\t|\t%d\t|%d\n|",i+1,t-ar[i],t-ar[i]-bt[i]);
            tat=wt+t-ar[i];
            wt=tat+t-ar[i]-bt[i];
            f=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(ar[i+1]<=t)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    printf("Average Waiting Time:%f",wt/n);
    printf("Average TAT Time:%f",tat/n);
    return 0;
}