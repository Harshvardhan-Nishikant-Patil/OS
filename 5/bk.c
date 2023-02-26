#include<stdio.h>
#include<stdbool.h>
#define n 5
#define m 3
int avl[m];
int mx[n][m];
int nd[n][m];
int aloc[n][m];
bool issf()
{
    int wk[m];
    int fin[n];
    int seq[n];
    for(int i=0;i<n;i++)
    {
        fin[i]=false;
    }
    for(int j=0;j<m;j++)
    {
        wk[j]=avl[j];
    }
    for(int k=0;k<n;k++)
    {
        bool first=true;
        for(int i=0;i<n;i++)
        {
            if(fin[i]==true)
                continue;
        bool last=true;
        for(int j=0;j<m;j++)
        {
            if(nd[i][j]>wk[j])
                last=false;
        }
        if(last)
        {
            first=false;
            for(int j=0;j<m;j++)
            {
                wk[j]+=aloc[i][j];
            }
            fin[i]=true;
            seq[k]=i;
            break;
        }
        }
        if(first)
            return false;
    }
    printf("\nSequence\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",seq[i]);
    }
    printf("\n");
    return true;
}
void rr()
{
    int pid;
    printf("Enter Process ID:\n");
    scanf("%d",&pid);
    pid--;
    int r[m];
    printf("Enter Request Vector\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&r[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(nd[pid][i]<r[i])
        {
            printf("Can't Done\n");
        }
    }
    for(int i=0;i<m;i++)
    {
        if(avl[i]<r[i])
        {
            printf("\nWait\n");
        }
    }
    for(int i=0;i<m;i++)
    {
        avl[i]-=r[i];
        aloc[pid][i]+=r[i];
        nd[pid][i]-=r[i];
    }
    if(issf())
    {
        printf("Is in Safe State\n");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            avl[i]+=r[i];
            aloc[pid][i]-=r[i];
            nd[pid][i]+=r[i];
        }
        printf("Taken Back\n");
    }
}
void main()
{
    printf("Enter Availble Vector\n");
    for(int i=0;i<m;i++){
    scanf("%d",&avl[i]);
    }
    printf("Enter the Max Matrix:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mx[i][j]);
        }
    }
    printf("Enter the Allocation Matrix:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&aloc[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            nd[i][j]=mx[i][j]-aloc[i][j];
        }
    }
    while(1)
    {
        issf();
        rr();
    }
}