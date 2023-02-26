#include<stdio.h>

void srt(int a[],int n);

void main()
{
    printf("\nEnter No. of Tracks\n");
    int n;
    scanf("%d",&n);
    int l;
    printf("\nEnter Length\n");
    scanf("%d",&l);
    int hd;
    printf("\nEnter Head Position\n");
    scanf("%d",&hd);
    int a[n];
    printf("\nEnter the all Tracks:\n");
    for(int i=0;i<n-1;i++)
    {
        scanf("%d ",&a[i]);
    }
    srt(a,n);
    int ans=((l-1)-hd)+((l-1)-a[0]);
    printf("Total Head Movement:%d\n",ans);
}

void srt(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void srrt(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
  
      }  }