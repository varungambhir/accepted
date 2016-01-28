//ACM14KG3
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
#define MOD 100000000


int main(int argc, char const *argv[])
{
    inputfile();cpp_input();
    int t1;
    cin>>t1;
    while(t1--)
    {
        string s , t;
        int m;
        string temp;
        cin>>s>>t>>m;

        int a[26]={0} , b[26]={0};

        FOR(i,0,s.size())
        a[s[i]-'a']++;

        FOR(i,0,t.size())
        b[t[i]-'a']++;

        matrix G(26,vector<ll>(26,0));

        FOR(i,0,m)
        {
            cin>>temp;
            G[temp[0]-'a'][temp[3]-'a'] = 1;
        }
        if(s.size()!=t.size())
        {
            cout<<"NO\n";
            continue;
        }
        if(s==t)
        {
            cout<<"YES\n";
            continue;
        }
        /*FOR(i,0,26)
        {
            G[i][i]=1;
        }*/

        FOR(k,0,26)
        {
            FOR(i,0,26)
            {
                FOR(j,0,26)
                {
                    G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
                }   
            }
        }

        bool flag = true;
        FOR(i,0,s.size())
        {   
            if(s[i]==t[i])
                continue;
             if(G[s[i]-'a'][t[i]-'a']==0)
                flag = false;
        }

        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}

