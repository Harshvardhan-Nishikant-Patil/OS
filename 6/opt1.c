#include<stdio.h>
int Framesize;
int CheckforPagefault(int page,int frames[])
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
void Displays(int frames[],int size,char hm)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d",frames[i]);
    }
    printf("%c\n",hm);
}
int FIFO(int req[],int seq)
{
    int size=0;
    int pagefaults=0;
    int ind=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(CheckforPagefault(req[i],frames))
        {
            if(size<Framesize)
            {
                pagefaults++;
                frames[i]=req[i];
                size++;
                Displays(frames,size,'M');
            }
            else
            {
                pagefaults++;
                frames[ind]=req[i];
                ind=(ind+1)%Framesize;
                Displays(frames,size,'M');
            }
        }
        else
        {
            Displays(frames,size,'H');
        }
    }
    return pagefaults;
}
int CheckLRU(int req[],int start,int frames[],int seq)
{
    int lru=seq;
    int ind;
    for(int i=0;i<Framesize;i++)
    {
        for(int j=start;j>=0;j--)
        {
            if(req[j]==frames[i])
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
int LRU(int req[],int seq)
{
    int size=0;
    int pagefaults=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(CheckforPagefault(req[i],frames))
        {
            if(size<Framesize)
            {
                frames[i]=req[i];
                pagefaults++;
                size++;
                Displays(frames,size,'M');
            }
            else
            {
                int ind=CheckLRU(req,i-1,frames,seq);
                frames[ind]=req[i];
                pagefaults++;
                Displays(frames,size,'M');
            }
        }
        else
        {
            Displays(frames,size,'H');
        }
    }
    return pagefaults;
}

int CheckOpt(int req[],int start,int seq,int frames[])
{
    int f=-1;
    int ind;
    for(int i=0;i<Framesize;i++)
    {
        int c=0;
        for(int j=start;j<seq;j++)
        {
            if(req[j]==frames[i])
            {
                if(f<j){
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
        }
    }
    return ind;
}
int OPT(int req[],int seq)
{
    int size=0;
    int pagefaults=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(CheckforPagefault(req[i],frames))
        {
            if(size<Framesize)
            {
                frames[i]=req[i];
                pagefaults++;
                size++;
                Displays(frames,size,'M');
            }
            else
            {
                int ind=CheckOpt(req,i-1,seq,frames);
                pagefaults++;
                frames[ind]=req[i];
                Displays(frames,size,'M');
            }
        }
        else
        {
            Displays(frames,size,'H');
        }
    }
    return pagefaults;
}
void main()
{
    int seq;
    printf("Enter No. of Sequences :\n");
    scanf("%d",&seq);
    int req[seq];
    printf("Enter sequqences:\n");
    for(int i=0;i<seq;i++)
    {
        printf("Frame: %d : \n",i+1);
        scanf("%d",&req[i]);
    }
    printf("Enter FrameSize\n");
    scanf("%d",&Framesize);
   // int ans1=FIFO(req,seq);
   // printf("FIFO:%d\n",ans1);
    int ans2=LRU(req,seq);
    printf("LRU:%d\n",ans2);
   // int ans3=OPT(req,seq);
    //printf("OPT:%d\n",ans3);
}