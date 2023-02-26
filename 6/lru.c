#include<stdio.h>
int Framesize;
int CheckPageFaults(int page,int frames[])
{
    for(int i=0;i<Framesize;i++)
    {
        if(frames[i]==page)
        {
            return 0;
        }
    }
    return 1;
}
void displays(int frames[],int size,char mh)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d",frames[i]);
    }
    printf("%c\n",mh);
}
int GetLRU(int reqseq[],int start,int frames[],int seq)
{
    int least=seq;
    int index;
    for(int i=0;i<Framesize;i++)
    {
        for(int j=start;j>=0;j--)
        {
            if(reqseq[j]==frames[i])
            {
                if(least>j)
                {
                    least=j;
                    index=i;
                }
                break;
            }
        }
    }
    return index;
}
int LRU(int reqseq[],int seq)
{
    int pagefaults=0;
    int size=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(CheckPageFaults(reqseq[i],frames))
        {
            if(size<Framesize)
            {
                frames[i]=reqseq[i];
                pagefaults++;
                size++;
                displays(frames,size,'M');
            }
            else
            {
                int ind=GetLRU(reqseq,i-1,frames,seq);
                frames[ind]=reqseq[i];
                pagefaults++;
                displays(frames,size,'M');
            }
        }
        else
        {
            displays(frames,size,'H');
        }
    }
    return pagefaults;
}
void main()
{
    int seq;
    printf("Enter No. of Sequences\n");
    scanf("%d",&seq);
    int reqseq[seq];
    printf("Enter Sequence of Frames:\n");
    for(int i=0;i<seq;i++)
    {
        printf("Frame: %d : \n",i+1);
        scanf("%d",&reqseq[i]);
    }
    printf("Enter Size of Frame\n");
    scanf("%d",&Framesize);
    int ans=LRU(reqseq,seq);
    printf("Answer is %d",ans);
}