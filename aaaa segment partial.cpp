#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 1000100
#define MOD 1000000007
#define endl "\n"
typedef pair<int,int> pii;
#define gc getchar_unlocked
    template <typename T>
void scanint(T &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

#define inf 0x7fffffff

ll gcd ( ll a, ll b )
{
    if ( a==0 ) return b;
  return gcd( b%a, a );
}
ll lcm ( ll a, ll b )
{
    return ((a*b)/gcd(a,b));
}


ll arr[MAX];
ll tree[MAX];

/**
 * Build and init tree
 */
void build_tree(ll node, ll a, ll b) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
            tree[node] = arr[a]; // Init value
        return;
    }
    
    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    
    tree[node] = (lcm(tree[node*2], tree[node*2+1]))%MOD;
    if(tree[node]<0)
        tree[node]+=MOD;
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(ll node, ll a, ll b, ll i, ll value) {
    
    if(a>b || a > i || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a == b) { // Leaf node
            tree[node] = value;
            return;
    }

    update_tree(node*2, a, (a+b)/2, i, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, value); // Updating right child
    if (node*2>b || node*2+1>b)
        {
            tree[node]=1;
        }
    
    tree[node] = (lcm(tree[node*2], tree[node*2+1]))%MOD; // Updating root with max value
     if(tree[node]<0)
        tree[node]+=MOD;
}

/**
 * Query tree to get max element value within range [i, j]
 */
ll query_tree(ll node, ll a, ll b, ll i, ll j) {
    
    if(a>b || a > j || b < i) return 1; // Out of range

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    ll res = (lcm(q1, q2))%MOD; // Return final result
    
    if (res<0)
        res+=MOD;
    return res;
}

int main() 
{
    ll N,choice,L,R,diff;
    ll tri;
    scanint(N);

    for(ll i = 0; i < N; i++) 
        scanint(arr[i]);
    
    build_tree(1, 0, N-1);
    //memset(lazy, 0, sizeof(lazy));

    scanint(tri);
    while(tri--)
    {
        scanint(choice);
        
        if(choice==1)
        {   
            scanint(L);scanint(R);
            update_tree(1,0,N-1,L-1,R);
        }
        else
        {   
            scanint(L);scanint(R);
            diff = (query_tree(1, 0, N-1, L-1, R-1))%MOD;
            if(diff<0)
                diff+=MOD;
            printf("%lld\n",diff);
        }
    }

    return 0;
}