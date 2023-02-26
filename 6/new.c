#include<stdio.h>
int framesize;
int checkpagefault(int page,int frame[])
{
    for(int i=0;i<framesize;i++)
    {
        if(frame[i]==page)
        {
            return 0;
        }
    }
    return 1;
}
int prinframe(int frame[],int size,char hm)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d",frames[i]);
    }
    printf("%c\n",hm);
}
int fifo(int rq[],int seq)
{
    int sum=0;
    int ind=0;
    int numberofpagefault=0;
    int frame[framesize];
    for(int i=0;i<seq;i++)
    {
        if(checkpagefault(rq[i],frames))
        {
            if(size<framesize)
            {
                numberofpagefault++;
                frame[i]=rq[i];
                sum++;
                prinframe(frames,size,'m';)
            }
            else
            {
                numberofpagefault++;
                frame[ind]=rq[i];
                ind=(ind+1)%framesize;
                prinframe(frames,size,'m';)
            }
        }
        else
        {
            prinframe(frame,size,'h');
        }
    }
    return numberofpagefault;
}