#include<stdio.h>
#include<stdbool.h>
#define n 5
#define m 3
int avl[m];
int alc[n][m];
int nd[n][m];
int mx[n][m];
bool issf()
{
    int fin[n];
    int wk[m];
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
                wk[j]=wk[j]+alc[i][j];
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
        printf("%d\n",seq[i]+1);
    }
    printf("\n");
    return true;
}
void rr()
{
    int pid;
    printf("\nEnter Process No.\n");
    scanf("%d",&pid);
    pid--;
    int r[m];
    printf("ENter Request Vector\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&r[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(nd[pid][i] < r[i])
        {
            printf("Need can't be less than Request:\n");
            return;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(avl[i] < r[i])
        {
            printf("Must Wait\n");
            return ;
        }
    }
    for(int i=0;i<m;i++)
    {
        avl[i]-=r[i];
        alc[pid][i]+=r[i];
        nd[pid][i]-=r[i];
    }
    if(issf())
    {
        printf("\nIs in Safe Sequence\n");
    }
    else
    {
        for(int i=0;i<m;i++){
        avl[i]+=r[i];
        alc[pid][i]-=r[i];
        nd[pid][i]+=r[i];
        }
        printf("Going back\n");
    }
}
void main()
{
    printf("\nEnter Availble Matrix\n");
    for(int i=0;i<m;i++)
    {
    scanf("%d",&avl[i]);
    }
    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alc[i][j]);
        }
    }
    printf("Enter Max Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mx[i][j]);
        }
    }
    printf("Need Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            nd[i][j]=mx[i][j]-alc[i][j];
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d",nd[i][j]);
        }
    }
    
    while(1)
    {
        issf();
        rr();
    }
}