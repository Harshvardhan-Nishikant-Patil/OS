#include<stdio.h>
#include<stdbool.h>
#define n 5
#define m 3
int available[m];
int need[n][m];
int allocated[n][m];
int max[n][m];
bool issafe()
{
    int finish[n];
    int sequence[n];
    int work[m];
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
                if(need[i][j]>work[j])
                    last=false;
            }
            if(last)
            {
                first=true;
                for(int j=0;j<m;j++)
                {
                    work[j]=work[j]+allocated[i][j];
                }
                finish[i]=true;
                sequence[k]=i;
                break;
            }
        }
        if(first)
        {
            return false;
        }
    }
    printf("\nHello");
    printf("\nSequences:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",sequence[i]+1);
    }
    printf("\n");
    return true;
}
void Resource_Request()
{
    int pid;
    printf("Enter Process No.:\n");
    scanf("%d",&pid);
    pid--;
    int request[m];
    printf("\nEnter Request Vector:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&request[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(need[pid][i]<request[i])
        {
            printf("Can't Be allocated\n");
            return ;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(available[i]<request[i])
        {
            printf("Wait for Sometime\n");
            return ;
        }
    }
    for(int i=0;i<m;i++)
    {
        available[i]-=request[i];
        allocated[pid][i]+=request[i];
        need[pid][i]-=request[i];
    }
    if(issafe())
    {
        printf("It is in Safe State\n");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            available[i]+=request[i];
            allocated[pid][i]-=request[i];
            need[pid][i]+=request[i];
        }
        printf("Taken Back\n");
    }
}
void main()
{
    printf("Enter Available Vector:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }
    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("Enter Max Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }
    while(1)
    {
        issafe();
        Resource_Request();
    }
}