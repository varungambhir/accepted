#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define mpp make_pair
#define pb push_back
#define FOR(i,a,n) for(int (i)=(a);(i) < (n); ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define FF(i,a,n) for ((i) = (a); (i)<(n);++(i))
#define REP(i,a,n) for ((i) = (a); (i)<=(n);++(i))
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define all(c) c.begin(),c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define abs(x) ((x)<0 ? -(x) : (x))
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >
//vector< vector<int> >Matrix(N, vector<int>(M,0));
inline void inputfile()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
#define MAX 100003
#define MOD 1000000007

struct Pt{
    int nu,de;
}P[2001];

vector<int> S;
vector< Pt > V;

bool cmp(Pt A, Pt B)
{
    if(A.nu<B.nu)
        return true;
    else if(A.nu==B.nu)
    {
        if(A.de<B.de)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inputfile();
    int n,x,y,i,j,x1,y1,x2,y2,g;
    ll t,a;
    ll ans=0;

    cin>>n;

        for(i=0;i<n;i++)
        cin>>P[i].nu>>P[i].de;

    if(n<3)
    {

        cout<<0;
        return 0;
    }



    for(i=0;i<n;i++)
    {
        x1 = P[i].nu;
        y1 = P[i].de;

        V.clear();
        S.clear();

        for(j=i+1;j<n;j++)
        {
            x2 = P[j].nu;
            y2 = P[j].de;

            if(y2-y1==0)
            {
                V.pb(Pt{0,0});
            }

            else if(x2-x1==0)
            {
                V.pb(Pt {1000,1000});
            }

            else
            {
                y=y2-y1;
                x=x2-x1;
                g = __gcd(x,y);
                y = y/g;
                x=x/g;
                V.pb(Pt{x,y});//????
            }
        }

        sort(V.begin(),V.end(),cmp);

        t=V.size();


        cout<<"ANS : "<<ans<<" t : "<<t;
        ans += (t*(t-1))/2;
        cout<<"\nANS after add  : "<<ans<<"\n";
        int lel=1;

        for(j=1;j<t;j++)
        {
            if(V[j].nu==V[j-1].nu && V[j].de==V[j-1].de)
                lel++;
            else
            {
                S.pb(lel);
                lel=1;
            }
        }

        S.pb(lel);

        for(j=0;j<S.size();j++)
        {
            if(S[j]==1)
                continue;
            else
            {
                a = S[j];
                cout<<"ANS : "<<ans<<" a : "<<a<<"\n";
                ans=ans- (a*(a-1))/2;
            }
        }

        cout<<"sub : ANS : "<<ans<<"\n";
        cout<<"---------------------\n";

    }

    cout<<ans;

    return 0;
}
