#include<stdio.h>
int Framesize;
int CheckPageFault(int page,int frames[])
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
int FIFO(int reqseq[],int seq)
{
    int size=0;
    int pagefaults=0;
    int index=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(CheckPageFault(reqseq[i],frames))
        {
            if(size<Framesize)
            {
                pagefaults++;
                frames[i]=reqseq[i];
                size++;
                Displays(frames,size,'M');
            }
            else
            {
                pagefaults++;
                frames[index]=reqseq[i];
                index=(index+1)%Framesize;
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
    printf("Enter the No. of Frames\n");
    scanf("%d",&seq);
    int reqseq[seq];
    printf("Enter Frame Sequences:\n");
    for(int i=0;i<seq;i++)
    {
        printf("Frame: %d : \n",i+1);
        scanf("%d",&reqseq[i]);
    }
    printf("Enter Size of Frame\n");
    scanf("%d",&Framesize);
    int ans=FIFO(reqseq,seq);
    printf("The Answer is: %d :\n",ans);
}