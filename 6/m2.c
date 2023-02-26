#include<stdio.h>
 int frmsz;
 int chkpgflt(int pg,int frm[])
 {
    for(int i=0;i<frmsz;i++)
    {
        if(frm[i]==pg)
        {
            return 0;
        }
    }
    return 1;
 }
 void dis(int frms[],int s,char hm)
 {
    printf("\n");
    for(int i=0;i<s;i++)
    {
        printf("%d",frms[i]);
    }
    printf("%c\n",hm);
 }
 int fifo(int resq[],int seq)
 {
    int s=0;
    int frms[frmsz];
    int pgflt=0;
    int ind=0;
    for(int i=0;i<seq;i++)
    {
        if(chkpgflt(resq[i],frms))
        {
            if(s<frmsz)
            {
                pgflt++;
                frms[i]=resq[i];
                s++;
                dis(frms,s,'m');
            }
            else
            {
                pgflt++;
                frms[ind]=resq[i];
                ind=(ind+1)%frmsz;
                dis(frms,s,'m');
            }
        }
        else
        {
            dis(frms,s,'h');
        }
    }    
    return pgflt;
 }
 void main()
 {
    int seq;
    printf("\nEnter no. of Sequences:");
    scanf("%d",&seq);
    int reqs[seq];
    for(int i=0;i<seq;i++)
    {
        printf("Enter Sequence:\n%d",i+1);
        scanf("%d",&reqs[i]);
    }
    printf("Enter Framesize\n");
    scanf("%d",&frmsz);
    int ans=fifo(reqs,seq);
    printf("Faults:%d\n",ans);

 }