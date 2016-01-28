#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAX 1000010
#define MOD 1000000007

ll arr[MAX] , tree[MAX] , lazy[MAX];
//1 -indexed
void build_tree(ll node, ll a,ll b)
{
    if(a>b)
        return;
    if(a==b){
        tree[node] = arr[a];
        return;
    }
    build_tree(L,a,(a+b)/2);
    build_tree(R,1+(a+b)/2,b);

    tree[node] = max(tree[node*2],tree[1+node*2]);
    return;
}

void update_tree(ll node,ll a,ll b,ll i,ll j,ll value)
{
    if(lazy[node]!=0)//This node needs to be updated
    {
        tree[node] += lazy[node];
        //tree mein lazy node update kari
        if(a!=b)
        {
           lazy[node*2] += lazy[node]; 
           lazy[1+node*2] += lazy[node];
         //L & R child mein lazy node update kari
        }
        
        lazy[node] = 0;//reset it
    }

    if(a>b || j<a || b<i)// Current segment is not within range [i, j]
        return;

    if(a>=i && b<=j) //segment within fully range
    {
        tree[node] += value;

        if(a!=b)//not leaf toh mark for lazy update uske child nodes
        {
            lazy[node*2] += value;
            lazy[1+node*2] += value;
        }
        return;
    }

    update_tree(node*2,a,(a+b)/2,i,j,value);
    update_tree(1+node*2,1+(a+b)/2,b,i,j,value);

    tree[node] = max(tree[L],tree[R]);
    return;
}

ll query_tree(ll node,ll a,ll b,ll i,ll j)
{
    if(a>b | j<a || b<i)
    {
        return -MOD;//out of range
    }

    if(lazy[node] !=0 )//This node needs to be updated
    {
        tree[node] += lazy[node];//Update it

        if(a!=b)//not a leaf node
        {
            lazy[L] += lazy[node];
            lazy[R] += lazy[node];
        }

        lazy[node] = 0;
    }
    if(i<=a && b<=j )
        return tree[node];

    ll q1 = query_tree(L,a,(a+b)/2,i,j);
    ll q2 = query_tree(R,1+(a+b)/2,b,i,j);

    return max(q1,q2);
}

int main() {
    int N = 15;
    for(int i = 0; i < N; i++) arr[i] = 1;

    build_tree(1, 0, N-1);

    memset(lazy, 0, sizeof lazy);

    update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
    update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
    update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

    cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
}