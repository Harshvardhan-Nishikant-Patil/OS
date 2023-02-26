#include<stdio.h>
int Framesize;
int checkpagefault(int pages,int frames[])
{
    for(int i=0;i<Framesize;i++)
    {
        if(frames[i]==pages)
        {
            return 0;
        }
    }
    return 1;
}
void dis(int frames[],int size,char hm)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("\n%d",frames[i]);
    }
    printf("%c\n",hm);
}
int fifo(int requestseq[],int seq)
{
    int size=0;
    int pagefaults=0;
    int index=0;
    int frames[Framesize];
    for(int i=0;i<seq;i++)
    {
        if(checkpagefault(requestseq[i],frames))
        {
            if(size<Framesize)
            {
                pagefaults++;
                frames[i]=requestseq[i];
                size++;
                dis(frames,size,'M');
            }
            else
            {
                pagefaults++;
                frames[index]=requestseq[i];
                index=(index+1)%Framesize;
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
void main()
{
    int seq;
    printf("Enter No. of Size\n");
    scanf("%d",&seq);
    int request[seq];
    for(int i=0;i<seq;i++)
    {
        printf("Enter the Track:%d",i+1);
        scanf("%d",&request[i]);
    }
    printf("Enter Framesize:\n");
    scanf("%d",&Framesize);
    int ans=fifo(request,seq);
    printf("\n%d",ans);
}