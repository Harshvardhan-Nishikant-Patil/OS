#include<stdio.h>
int framesize;
int chkpgflt(int pg,int frm[])
{
    for(int i=0;i<framesize;i++)
    {
        if(frm[i]==pg)
        {
            return 0;
        }
    }
    return 1;
}
void dis(int frm[],int s,char hm)
{
    printf("\n");
    for(int i=0;i<s;i++)
    {
        printf("\n%d",frm[i]);
    }
    printf("%c",hm);
}
int fifo(int reqs[],int seq)
{
    int s=0;
    int frm[framesize];
    int pgfalts=0;
    int id=0;
    for(int i=0;i<seq;i++)
    {
        if(chkpgflt(reqs[i],frm))
        {
            if(s<framesize){
            pgfalts++;
            frm[i]=reqs[i];
            s++;
            dis(frm,s,'m');
        }
        else
        {
            pgfalts++;
            frm[id]=reqs[i];
            id=(id+1)%framesize;
            dis(frm,s,'m');
        }}
        else
        {
            dis(frm,s,'h');
        }
    }
    return pgfalts;
}
void main()
{
    int seq;
    printf("Enter no. of Sequenece\n");
    scanf("%d",&seq);
    int req[seq];
    for(int i=0;i<seq;i++)
    {
        printf("Enter Seq:",i+1);
        scanf("%d",&req[seq]);
    }
    printf("Enter Frame size\n");
    scanf("%d",&framesize);
    int ans=fifo(req,seq);
    printf("%d\n",ans);
}