#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 100000
#define MOD 1000000007
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct node{
    ll n;
    node *left, *right;
};

class SegmentTree
{
    node *p;//base pointer;
    ll len;
    vector<ll> arr;

public:
    ll best;

    SegmentTree()
    {
        len = 0;
        p = NULL;
        best = LONG_MAX;//
    }

    node *construct(vector<ll> v)
    {
        node *q;
        q = new node;

        if(len==0)
        {
            len = v.size();
            arr = v;
        }

        if(v.size()==1)
        {
            q->n = v[0];
            q->left = NULL;
            q->right = NULL;
        }
        else
        {
            ll mid = (v.size() - 1)/2;
            // q->left
            (*q).left = construct( vector<ll>(v.begin(), v.begin() + mid + 1));
            (*q).right = construct( vector<ll>(v.begin()+mid+1,v.end()) ) ;
            (*q).n = (*q).left->n + (*q).right->n;

        }
         p = q;
         return q;
    }


    void Display(queue <node*> q)
    {
        queue<node*> qq;
        while (!q.empty() )
        {
            node *ele = q.front();
            if (ele->left!=NULL)
            {
                qq.push(ele->left);
            }
            if(ele->right!=NULL)
            {
                qq.push(ele->right);
            }   
            q.pop();
            cout<<ele->n<<" ";
        }
        cout<<endl;

        if(!qq.empty())
            Display(qq);
    }

    void print()
    {
        queue<node*>q;
        q.push(p);
        Display(q);
        cout<<"\n\n\n";
    }
    ll size()
    {
        return len;
    }
    ll getstum(ll x ,ll y, node *ptr=NULL,ll start=1,ll end=-1)
    {
        if(start==1 && end==-1)
        {
            ptr = p;
            end = len;
        }

        if(ptr==NULL)
        {
            return 0;
        }

        ll m = (end+start)/2;

        if(x> end || y < start)//totally out of range
        {
            return 0;
        }
        if(x<=start && end<=y)//totally inside range
        {
            return ptr->n;
        }
        cout << " RANGE: " << start << " " << end << endl;
    
        return getstum(x,y,ptr->left,start,m) + getstum(x,y,ptr->right,m+1,end);
    }

    int update(ll index,ll val,node *ptr=NULL,ll start=1, ll end=-1)
    {
        if(start==1 && end==-1)
        {
            ptr = p;
            end = len;
        }
        if(ptr == NULL)
            return 0;

        cout<<ptr->n<<" -- "<<start<<" "<<end<<endl;
        ll diff = val - arr[index-1];
        ll mid = (start+end)/2;
        if(start > index || end < index)
            return 0;
        else{
            ptr->n += diff;
            update(index,val,ptr->left,start,mid);
            update(index,val,ptr->right,mid+1,end);
        }
    }

};

int main() {
    ll n;
    cin>>n;
    
    vector<ll> v;
    
    FOR(i,0,n) 
    {
        ll x; cin>>x;
        v.pb(x);
    }
    
    SegmentTree tree;
    tree.construct(v);
    cout << "\n\n";
    tree.print();
    
    ll m;
    cin>>m;
    
    while(m--) {
        ll x, y;
        cin>>x>>y;
        cout << tree.getstum(x,y) << endl;
        
    }
    
}