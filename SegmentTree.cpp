#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007


struct SegmentTreeNode
{
    //aggregate statics
    int val;
    SegmentTreeNode()
    {
        val = 0;
    }

    void assignLeaf(int value)
    {
        val = value;
        return;
    }

    void merge(SegmentTreeNode &left, SegmentTreeNode &right)
    {
        val = left.val + right.val;
    }

    int getValue()
    {
        return val;
    }
};

//T is the type of input array elements
//V is type of required aggregate statistics
//template<class T,class V>
class SegmentTree
{
    SegmentTreeNode* nodes;
    int N;

public:
    SegmentTree(int arr[],int N)
    {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr,1,0,N-1);
    }

    ~SegmentTree()
    {
        delete[] nodes;
    }

    int getValue(int lo,int hi)
    {
        SegmentTreeNode result = getValue(1,0,N-1,lo,hi);
        return result.getValue();
    }

    void update(int index,int value)
    {
        update(1,0,N-1,index,value);
        return;
    }

    void printt()
    {
        FOR(i,1,N+1)
        {
            cout<<nodes[i].val<<" ";
        }
    }
   

private:
    void buildTree(int arr[],int stIndex,int lo,int hi)
    {
        if(lo == hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2*stIndex;
        int right = 2*stIndex + 1;
        int mid = (lo + hi)/2;
    
        buildTree(arr,left,lo,mid);
        buildTree(arr,right,mid+1,hi);

        nodes[stIndex].merge(nodes[left],nodes[right]);
        return;
    }

    SegmentTreeNode getValue(int stIndex,int left,int right,int lo,int hi)
    {
        if(left == lo && right == hi)
        {
            return nodes[stIndex];
        }

        int mid = (left + right)/2;
        if(lo > mid)
        {
            return getValue(2*stIndex+1,mid+1,right,lo,hi);        
        }
        if( hi <= mid)
        {
            return getValue(2*stIndex,left,mid,lo,hi);
        }

        SegmentTreeNode leftResult = getValue(2*stIndex,left,mid,lo,mid);
        SegmentTreeNode rightResult= getValue(2*stIndex+1,mid+1,right,mid+1,hi);        
        SegmentTreeNode result;
        
        result.merge(leftResult,rightResult); 
        return result;
    }

    int getSegmentTreeSize(int N)
    {
        int size = 1;
        for(;size < N; size = size<<1);
        return size<<1;
    }

    void update(int stIndex,int lo,int hi,int index,int value)
    {
        if(lo == hi)
        {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2*stIndex;
        int right = 2*stIndex + 1;
        int mid = (lo + hi)/2;
        
        if(index <= mid)
            update(left,lo,mid,index,value);
        else
            update(right,mid+1,hi,index,value);

        nodes[stIndex].merge(nodes[left],nodes[right]);
        return;
    }

    

};

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    SegmentTree a(arr,8);
    a.printt();
    return 0;
}