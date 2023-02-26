#include<stdio.h>
int Framesize;
int Checkpagefaults(int page,int frames[])
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
void dis(int frames[],int size,char mh)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d",frames[i]);
    }
    printf("%c\n",mh);
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
int LRU(int seqreq[],int seq)
{
    int size=0;
    int pagefaults=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(Checkpagefaults(seqreq[i],frames))
        {
            if(size<Framesize)
            {
                frames[i]=seqreq[i];
                pagefaults++;
                size++;
                dis(frames,size,'M');
            }
            else
            {
                int ind=CheckLRU(seqreq,i-1,frames,seq);
                frames[ind]=seqreq[i];
                pagefaults++;
                dis(frames,size,'M');
            }
        }
        else
        {
            dis(frames,size,'H');
        }
    }
    return pagefaults;
}