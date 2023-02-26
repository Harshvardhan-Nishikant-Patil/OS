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
void Displays(int frames[],int size,char mh)
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
    int lru=seq;
    int index;
    for(int i=0;i<Framesize;i++)
    {
        for(int j=start;j>=0;j--)
        {
            if(reqseq[j]==frames[i])
            {
                if(lru>j)
                {
                    lru=j;
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
    int size=0;
    int pagefaults=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(Checkpagefault(reqseq[i],seq))
        {
            if(size<Framesize)
            {
                frames[i]=reqseq[i];
                pagefaults++;
                size++;
                Displays(frames,size,'M');
            }
            else
            {
                int ind=GetLRU(reqseq,i-1,frames,seq);
                frames[ind]=reqseq[i];
                pagefaults++;
                Displays(frames,size,'M');
            }
            else
            {
                Displays(frames,size,'H');
            }
        }
    }
    return pagefaults;
}
void main()
{
    
}