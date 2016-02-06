
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
const int N=1e5+5;
struct Query
{
    int st,ed,id;
    Query(){}
    Query(int a,int b,int c){st=a;ed=b;id=c;}
    bool operator<(const Query &b)const
    {
        return ed<b.ed;
    }
};
//http://codeforces.com/contest/221/problem/D
struct node
{
    int lft,rht,sum;
    int mid(){return lft+(rht-lft)/2;}
};
struct Segtree
{
    node tree[N*4];
    void relax(int ind)
    {
        int &sum=tree[ind].sum;
        if(sum!=0)
        {
            tree[LL(ind)].sum+=sum;
            tree[RR(ind)].sum+=sum;
            sum=0;
        }
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;  tree[ind].rht=rht;
        tree[ind].sum=0;
        if(lft!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int be,int end,int ind,int valu)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(be<=lft&&rht<=end) tree[ind].sum+=valu;
        else 
        {
            relax(ind);
            int mid=tree[ind].mid();
            if(be<=mid) updata(be,end,LL(ind),valu);
            if(end>mid) updata(be,end,RR(ind),valu);
        }
    }
    int query(int pos,int ind)
    {
        if(tree[ind].lft==tree[ind].rht) return tree[ind].sum;
        else 
        {
            relax(ind);
            int mid=tree[ind].mid();
            if(pos<=mid) return query(pos,LL(ind));
            else return query(pos,RR(ind));
        }
    }
}seg;

vector<Query> query;
vector<int>pos[N];
int data[N],cnt[N],res[N];
pair<int,int> pre[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++) scanf("%d",&data[i]);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        query.push_back(Query(a,b,i));
    }
    sort(query.begin(),query.end());

    int ind=0;
    seg.build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        int valu=data[i];
        if(valu<=n)
        {
            cnt[valu]++;
            pos[valu].push_back(i);
            if(cnt[valu]==valu)
            {
                pre[valu]=make_pair(1,pos[valu][0]);
                seg.updata(pre[valu].first,pre[valu].second,1,1);
            }
            else if(cnt[valu]>valu)
            {
                seg.updata(pre[valu].first,pre[valu].second,1,-1);
                pre[valu]=make_pair(pre[valu].second+1,pos[valu][cnt[valu]-valu]);
                seg.updata(pre[valu].first,pre[valu].second,1,1);
            }
        }
        while(query[ind].ed==i&&ind<m)
        {
            res[query[ind].id]=seg.query(query[ind].st,1);
            ind++;
        }
    }
    for(int i=0;i<m;i++) printf("%d\n",res[i]);
    return 0;
}