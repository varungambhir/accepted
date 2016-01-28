#include<bits/stdc++.h>
using namespace std;
int vis[15],ans;
void rec(int ind,int num)
{
    if(ind==10)
    {
        //cout<<num<<endl;
        int arr[15]={0},bu=num;
        int gh=0;
        while(bu>0)
        {
            arr[gh++]=bu%10;
            bu=bu/10;  
        }
        int numm=arr[gh-1],yo=1,jk=2,f=0;
        if(numm%1!=0)
            f=1;
        for(int j=gh-2;j>=0;j--)
        {
            numm=numm*10+arr[j];
            if(numm%jk!=0)
            {
                f=1;
                break;
            }
            jk++;
         }
         if(f==0)
             ans=num;
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            //cout<<"d "<<pow(10,ind-1)*i<<endl;
            //cout<< num+pow(10,ind-1)*i <<endl;
            rec(ind+1,num+pow(10,ind-1)*i);
            vis[i]=0;
        }
    }
    return;
}
int main()
{
    rec(1,0);
    cout<<ans;
    return 0;
}