#include<stdio.h>
int Framesize;
int CheckLRU(int seqreq[],int st,int frame[],int seq)
{
    int lru=seq;
    int ind=0;
    for(int i=0;i<Framesize;i++)
    {
        for(int j=start;j>=0;j--)
        {
            if(seqreq[j]==frame[i])
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
        if(seqreq[i],frames)
        {
            if(size<Framesize)
            {
                frames[i]=seqreq[i];
                pagefaults++;
                size++;
                dis
            }
            else
            {
                int id=CheckLRU(seqreq,i-1,frames,seq);
                frames[id]=seqreq[i];
                pagefaults++
            }
        }
    }
}