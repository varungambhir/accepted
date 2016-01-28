#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
#define MAXN 40003  
using namespace std;  
typedef struct node  
{  
    int l,r;  
} node;  
int main()  
{  
    freopen("input.in","r",stdin);  
    int x[MAXN*2],vis[MAXN],f[MAXN];  
    node post[MAXN];  
    int cas,n,hg,ans;  
    scanf("%d",&cas);  
    while(cas--)  
    {  
        scanf("%d",&n);  
        memset(vis,0,sizeof(vis));  
        hg=0;  
        for(int i=0; i<n; i++)  
        {  
            scanf("%d%d",&x[hg],&x[hg+1]);  
            post[i].l=x[hg];  
            post[i].r=x[hg+1];  
            hg+=2;  
        }  
        sort(x,x+hg);  
        int len=unique(x,x+hg)-x;  
        for(int i=0; i<n; i++)  
        {  
            int L=lower_bound(x,x+len,post[i].l)-x;  
            int R=lower_bound(x,x+len,post[i].r)-x;  
            for(int j=L; j<=R; j++)  
                f[j]=i;  
        }  
        ans=0;  
        for(int i=0; i<len; i++)  
        {  
            if(!vis[f[i]])  
                ans++;  
            vis[f[i]]=1;  
        }  
        cout<<ans<<endl;  
    }  
    return 0;  
}  