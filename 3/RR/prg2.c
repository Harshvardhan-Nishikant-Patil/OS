#include<stdio.h>
int main()
{
    int n,i,c,t,r,q,ar[10],bt[10],rt[10],f=0;
    double wt=0,tat=0;
    printf("\nEnter the No. of Processes\n");
    scanf("%d",&n);
    r=n;
    printf("\nEnter the Process Details:\n");
    for(int i=0;i<n;i++)
    {
        printf("Arrival Time: %d : ",i+1);
        printf("\n");
        scanf("%d",&ar[i]);
        printf("Burst Time: %d : ",i+1);
        printf("\n");
        scanf("%d",&ar[i]);
        rt[i]=bt[i];
    }
    printf("\nEnter The Time of Quantum\n");
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
            printf("\nP[%d]\t|\t%d\t|\t%d\n",i+1,t-ar[i],t-ar[i]-bt[i]);
            tat=tat+t-ar[i];
            wt=wt+t-ar[i]-bt[i];
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