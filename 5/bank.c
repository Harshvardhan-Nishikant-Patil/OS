#include<stdio.h>
#include<stdbool.h>
#define n 5
#define m 3
int need[n][m];
int allocation[n][m];
int mx[n][m];
int availble[m];
void prin()
{
  printf("\n\n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",availble[i]);
    }
    printf("\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",mx[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
}
bool issafe()
{
    int finish[n];
    int sequ[n];
    int work[m];
    for(int i=0;i<n;i++)
    {
        finish[i]=false;
    }
    for(int i=0;i<m;i++)
    {
        work[i]=availble[i];
    }
    for(int k=0;k<n;k++)
    {
        bool first=true;
        for(int i=0;i<n;i++)
        {
            if(finish[i]==true)
            {
                continue;
            }
            bool last=true;
            for(int j=0;j<m;j++)
            {
                if(need[i][j]>work[j])
                {
                    last=false;
                }
            }
            if(last)
            {
                first=false;
                for(int j=0;j<m;j++)
                {
                    work[j]=work[j]+allocation[i][j];
                }
                finish[i]=true;
                sequ[k]=i;
                break;
            }
        }
        if(first)
        {
            prin();
            return false;
        }
    }
    printf("\nSequences:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",sequ[i]+1);
    }
    printf("\n");
return true;
}
void resource_request()
{
    int pid;
    printf("\nEnter Process Number:\n");
    scanf("%d",&pid);
    pid--;
    int req[m];
    printf("\nEnter Request Vector:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&req[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(need[pid][i]<req[i])
        {
            printf("can't Allocated\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(availble[i]<req[i])
        {
            printf("Wait for Sometimes\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        availble[i]-=req[i];
        allocation[pid][i]+=req[i];
        need[pid][i]-=req[i];
    }
    if(issafe())
    {
        printf("Is In Safe State\n");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
             availble[i]+=req[i];
             allocation[pid][i]-=req[i];
             need[pid][i]+=req[i];
        }
        printf("Taking Back\n");
    }
}
int main()
{
    printf("Enter Available Vector:\n");
    for(int i=0;i<m;i++)
    {
    scanf("%d",&availble[i]);
    }
    printf("\nEnter Allocation Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("\nEnter Max Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mx[i][j]);
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
        issafe();
        resource_request();
    }
    return 0;
}
/*
3   3   2

0   1   0
2   0   0   
3   0   2
2   1   1
0   0   2

7   5   3
3   2   2
9   0   2
2   2   2
4   3   3*/