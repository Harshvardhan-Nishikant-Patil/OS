#include <stdio.h>
#include <stdbool.h>

#define n 5
#define m 3

int available[m];
int allocation[n][m];
int max[n][m];
int need[n][m];

bool isSafe()
{
    int work[m];
    int sequence[n];
    int finish[n];
    for(int i=0;i<n;i++)
    {
        finish[i] = false;
    }
    for(int i=0;i<m;i++)
    {
        work[i] = available[i];
    }
    for(int k = 0;k<n;k++)
    {
        bool lflag = true;
        for(int i=0;i<n;i++)
        {
            if(finish[i] == true)
                continue;

            bool less = true;

            for(int j=0;j<m;j++)
            {
                if(need[i][j] > work[j])
                    less = false;
            }
            if(less)
            {
                lflag = false;
                for(int j = 0;j<m;j++)
                {
                    work[j] = work[j] + allocation[i][j];
                }
                finish[i] = true;
                sequence[k] = i;
                break;
            }
        }
        if(lflag)
        {
            return false;
        }
    }
    printf("Seqeunce = ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", sequence[i] +1);
    }
    printf("\n");
    return true;
}

void resource_request()
{
    printf("Enter process id : ");
    int pid;
    scanf(" %d", &pid);
    pid--; // 0 based indexing
    printf("Enter Request vector : ");
    int request[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d", &request[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(need[pid][i] < request[i])
        {
            printf("ERROR : Requested resource must be less than need.\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(available[i] < request[i])
        {
            printf("Process must wait some time till resources are available.\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }
    if(isSafe())
    {
        printf("Resources Allocated Successfully.\n");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            available[i] += request[i];
            allocation[pid][i] -= request[i];
            need[pid][i] += request[i];
        }
        printf("Going into unsafe state. Resource Allocation Aborted.\n");
    }
}

int main()
{
    printf("Enter Available Vector :\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d", &available[i]);
    }
    printf("Enter Allocation Matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter Max Matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    while(1)
    {
        isSafe();
        resource_request();
    }
    return 0;
}