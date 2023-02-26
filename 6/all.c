#include<stdio.h>
int Framesize;
int Checkpagefault(int page,int frames[])
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
void displays(int frames[],int size,char hm)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d",frames[i]);
    }
    printf("%c\n",hm);
}
int fifo(int reqseq[],int seq)
{
    int size=0;
    int pagefaults=0;
    int ind=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(Checkpagefault(reqseq[i],frames))
        {
            if(size<Framesize)
            {
                pagefaults++;
                frames[i]=reqseq[i];
                size++;
                displays(frames,size,'M');
            }
            else
            {
                pagefaults++;
                frames[ind]=reqseq[i];
                ind=(ind+1)%Framesize;
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
int CheckLRU(int reqseq[],int start,int frames[],int seq)
{
    int lru=seq;
    int ind;
    for(int i=0;i<Framesize;i++)
    {
        for(int j=start;j>=0;j--)
        {
            if(reqseq[j]==frames[i])
            {
                if(lru>j)
                {
                    lru=j;
                    ind=i;
                }
                break;
            }
        }
    }
    return ind;
}
int LRU(int reqseq[],int seq)
{
    int size=0;
    int pagefaults=0;
    int frames[Framesize];
    for(int i=0;i<size;i++)
    {
        if(Checkpagefault(reqseq[i],frames))
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
                int ind=CheckLRU(reqseq,i-1,frames,seq);
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
int CheckOPT(int reqseq[],int start,int seq,int frames[])
{
    int l=-1;
    int ind;
    for(int i=0;i<Framesize;i++)
    {
        int c=0;
        for(int j=start;j<seq;j++)
        {
            if(frames[i]==reqseq[j])
            {
                if(l<j)
                {
                    ind=i;
                    l=j;
                }
                c=1;
                break;
            }
            if(c==0)
                return i;
        }
    }
    return ind;
}
int OPT(int reqseq[],int seq)
{
    int size=0;
    int pagefaults=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(Checkpagefault(reqseq[i],frames))
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
                
                int ind=CheckOPT(reqseq,i-1,seq,frames);
                pagefaults++;
                frames[ind]=reqseq[i];
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
    printf("\nENter No. of seq\n");
    scanf("%d",&seq);
    int req[seq];
    printf("Enter sequence\n");
    for(int i=0;i<seq;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter Framesize\n");
    scanf("%d",&Framesize);
  //  int ans1=fifo(req,seq);
    //printf("Fifo:%d",ans1);
    int ans2=LRU(req,seq);
 printf("LRU:%d",ans2);
  //  int ans3=OPT(req,seq);
   // printf("OPT:%d",ans3);
}