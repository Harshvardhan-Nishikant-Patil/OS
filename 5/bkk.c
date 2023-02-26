#include<stdio.h>
#include<stdbool.h>
#define n 5
#define m 3
int available[m];
int mx[n][m];
int need[n][m];
int allocation[n][m];
bool issf()
{
    int finish[n];
    int work[m];
    int seq[n];
    for(int i=0;i<n;i++)
    {
        finish[i]=false;
    }
    for(int i=0;i<m;i++)
    {
        work[i]=available[i];
    }
    for(int k=0;k<n;k++)
    {
        bool first=true;
        for(int i=0;i<n;i++)
        {
            if(finish[i]==true)
                continue;
            bool last=true;
            for(int j=0;j<m;j++)
            {
                if(need[i][j]>available[j])
                    last=false;
            }
        
        if(last)
        {
            first=false;
            for(int j=0;j<m;j++)
            {
                work[j]+=allocation[i][j];
            }
            finish[i]=true;
            seq[k]=i;
            break;
        }
        }
        if(first)
        {
            return false;
        }
    }
    printf("\nSequence:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",seq[i]);
    }
    printf("\n");
    return true;
}
void rr()
{
    int pid;
    printf("\nEnter no. of Process\n");
    scanf("%d",&pid);
    pid--;
    int re[m];
    printf("Enter Req Vector\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&re[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(need[pid][i]<re[i])
        {
            printf("can't\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(available[i]<re[i])
        {
            printf("Wait\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        available[i]-=re[i];
        allocation[pid][i]+=re[i];
        need[pid][i]-=re[i];
    }
    if(issf())
    {
        printf("Safe\n");
    }
    else
    {
        for(int i=0;i<m;i++)
    {
        available[i]+=re[i];
        allocation[pid][i]-=re[i];
        need[pid][i]+=re[i];
    }
    printf("Taking back\n");
    }
}
void main()
{
    printf("enter ava\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }
    printf("\nmax:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mx[i][j]);
        }
    }
    printf("\nAlloc:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=mx[i][j]-allocation[i][j];
        }
    }
    while(1)
    {
        issf();
        rr();
    }
}