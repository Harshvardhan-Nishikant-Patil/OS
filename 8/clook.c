#include<stdio.h>
#include<stdbool.h>
void srt(int a[],int n);
int z;
int ans;
void main()
{
    int ans=0;
    bool ok=false;
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
    for(int i=hd;i>=0;i--)
    {
        
        for(int j=0;j<n;j++)
        {
            if(a[j]==i)
            {
                    z=a[j];
                    goto samp;
            }
        }
    }
    samp:
     ans=(a[6]-hd)+(a[6]-a[0])+(z-a[0]);
    printf("Head_Position:%d\n",ans);

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