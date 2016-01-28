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
#define F first
#define S second
#define PI acos(-1.0)
#define EPS 1e-9
#define Lf 2*r
#define Rg 2*r+1
#define M(x,i) memset(x,i,sizeof(x))
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define matrix vector< vector<ll> >

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
#define mod 1000000007


int main()
{
    inputfile();cpp_input();
    string a,b,c;
    vector< char > a1,b1,c1;
    map< char,int > mapsa,mapsb,mapsc;

    cin>>a>>b>>c;
//        mapsa.clear();mapsb.clear();mapsc.clear();



        FOR(i,0,a.size())
        {
            if(mapsa.count(a[i])==0)
            {
                a1.push_back(a[i]);
                mapsa[a[i]]=1;
            }
            else
            mapsa[a[i]]++;
        }
       FOR(i,0,b.size())
        {
            if(mapsb.count(b[i])==0)
            {
                b1.push_back(b[i]);
                mapsb[b[i]]=1;
            }
            else
            mapsb[b[i]]++;
        }
        FOR(i,0,c.size())
        {
            if(mapsc.count(c[i])==0)
            {
                c1.push_back(c[i]);
                mapsc[c[i]]=1;
            }
            else
            mapsc[c[i]]++;
        }

        int maxi1 =1234567;
        int maxi2 =1234567;
        int ratio1;
        FOR(i,0,b1.size())
        {
            ratio1 = mapsa[b1[i]] / mapsb[b1[i]];
            maxi1 = min(maxi1,ratio1);
        }
        FOR(i,0,c1.size())
        {
            ratio1 = mapsa[c1[i]] / mapsc[c1[i]];
            maxi2 = min(maxi2,ratio1);
        }

        if(maxi1 >= maxi2)
        {
            for(int i=1 ; i<=maxi1;i++)
            cout<<b;

            FOR(i,0,b1.size())
            {
                mapsa[b1[i]] -= (maxi1 * mapsb[ b1[i] ]);
            }
            FOR(i,0,a1.size())
            {
                if(mapsa[a1[i]]!=0)
                FOR(j,0,mapsa[a1[i]])
                {
                    cout<<(char)a1[i];
                }
            }

        }

        else
        {
            for(int i=1 ; i<=maxi2;i++)
            cout<<c;

            FOR(i,0,c1.size())
            {
                mapsa[c1[i]] -= (maxi2 * mapsc[ c1[i] ]);
            }
            FOR(i,0,a1.size())
            {
                if(mapsa[a1[i]]!=0)
                FOR(j,0,mapsa[a1[i]])
                {
                    cout<<(char)a1[i];
                }
            }
        }

    return 0;
}
