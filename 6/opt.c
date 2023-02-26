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
int dis(int frames[],int size,char hm)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d",frames[i]);
    }
    printf("%c\n",hm);
}
int chckOpt(int seqreq[],int start,int seq,int frames[])
{
    int f=-1;
    int ind;
    for(int i=0;i<Framesize;i++)
    {
        for(int j=start;j<seq;j++){
        int c=0;
        if(frames[i]==seqreq[j])
        {
            if(f<j)
            {
                ind=i;
                f=j;
            }
            c=1;
            break;
        }
    }
    if(c==0)
    {
        return i;
    }}
    return ind;
}
int opt(int reqseq[],int seq)
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
                dis(frames,signed,'M');
            }
            else
            {
                int ind=chckOpt(reqseq,i-1,seq,frames);
                pagefaults++;
                frames[ind]=reqseq[i];
                dis()
            }
        }
        else
        {
            dis()
        }
    }
    return pagefaults;
}
