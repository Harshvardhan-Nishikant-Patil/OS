#include<stdio.h>
int main()
{
    int i,n,t,r,q,ar[10],bt[10],rt[10],f=0;
    double wt=0,tat=0;
    printf("\nEnter No. of Processes\n");
    scanf("%d",&n);
    r=n;
    printf("\nEnter Process Details:\n");
    for(i=0;i<n;i++)
    {
        printf("\nArrival Time:%d:\n",i);
        scanf("%d",&ar[i]);
        printf("\nBurst Time:%d:\n",i);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\nEnter Time Quantum\n");
    scanf("%d",&q);
    for(t=0,i=0;r!=0;)
    {
        if(rt[i]<=q && rt[i]>0)
        {
            t+=rt[i];
            rt[i]=0;
            f=1;
        }
        else if(rt[i]>0)
        {
            rt[i]-=q;
            t+=q;
        }
        if(rt[i]==0 && f==1)
        {
            r--;
            printf("\tP[%d]\t|\t%d\t|\t%d\n",i+1,t-ar[i],t-ar[i]-bt[i]);
            wt+=t-ar[i]-bt[i];
            tat=t-ar[i];
        }
        if(i==n-1)
            i=0;
        else if(ar[i]<=t)
            i++;
        else
            i=0;
    }
    printf("Average Waiting Time:%f\n",wt/n);
    printf("Average TAT:%f\n",tat/n);
    return 0;
}