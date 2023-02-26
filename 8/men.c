#include<bits/stdc++.h>
using namespace std;
int comp(const void *a,const void *b)
{
    return (*(int *)a - *(int *)b);
}

void CLOOK(int n,int a[],int x)
{
    qsort(a,n,sizeof(int),comp);
    int total=a[n-1]-x;
    cout<<"\n"<<x;
    if(x>a[0])
    {
        total+=a[n-1]-a[0];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>x)
        cout<<"->"<<a[i];
    }
    int i;
    for(i=0;a[i]<x;i++)
    {
        cout<<"->"<<a[i];
    }
    if(a[0]<x)
    {
        total+=a[i-1]-a[0];
    }
    cout<<"total movement is\t"<<total;
    return;
    
}

void SCAN(int n,int a[],int len,int x)
{
    qsort(a,n,sizeof(int),comp);
    cout<<"\n"<<x;
    int total=len-1-x;
    if(x>a[0])
    {
        total+=len-1-a[0];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>x)
        cout<<"->"<<a[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<x)
        cout<<"->"<<a[i];
    }
    cout<<"total movement:\t"<<total;
    return;
}

void SSTF(int n,int a[],int x)
{
    int ind,min;
    bool done[n];
    cout<<"\n"<<x;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        ind=0;
        min=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(abs(x-a[j])<min && !done[j])
            {
                ind=j;
                min=abs(x-a[j]);
            }
        }
        sum+=min;
        x=a[ind];
        done[ind]=true;
        cout<<"->"<<a[ind];
    }
    cout<<"total time \t"<<sum;
    return;
}

int main()
{
    int n;
    cout<<"enter total no of requests\t";
    cin>>n;
    
    int a[n];
    cout<<"enter requests\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int r;
    cout<<"current position of the head\t";
    cin>>r;
    
    int len;
    cout<<"track length\t";
    cin>>len;
    
    int ch;
    do{
        cout<<"\n----------------MENU-----------------\n";
        cout<<"\t1.SSTF\n\t2.SCAN\n\t3.CLOOK\n";
        cout<<"enter choice\t";
        cin>>ch;
        switch(ch)
        {
            case 1:
            SSTF(n,a,r);
            break;
            
            case 2:
            SCAN(n,a,len,r);
            break;
            
            case 3:
           CLOOK(n,a,r);
            break;
        }
    }while(ch!=4);
    return 0;
}
