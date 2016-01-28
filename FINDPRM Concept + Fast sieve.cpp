#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define V(x) vector<x>
#define Sd(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define cpresent_vector(c,x) (find(all(c),x) != (c).end())
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
#define F1 first
#define S2 second
#define Lf 2*r
#define Rg 2*r+1
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define MAXNN 10000003
#define mod 1000000007

inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
inline void cpp_input()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);}


bool prime[MAXNN]={0};//prime
int ans[MAXNN];//second series
void fast_sieve()
{
	for (int i = 4; i <=MAXNN; i+=2)
	{
		prime[i]=true;
	}

    for(int i=3;i*i<=MAXNN;i+=2)
    {
    	if(!prime[i])
        for(int j=i*i;j<MAXNN;j=j+2*i)
        {
            prime[j]=true;//composite
        }
    }


    prime[2]=prime[3]=false;

    ans[2]=1;ans[3]=2;

	for(int i=4;i<=MAXNN;i++)
	{
		ans[i]=ans[i-1];
		//printf("%d %d\t",i,ans[i]);
		if(prime[i]==false)//is prime
			{
			    ans[i] = ans[i] + 1;
			//cout<<ans[i]<<"\t";
			}
		if( (prime[i/2]==false) && (!(i&1)) )
			{ ans[i] = ans[i] - 1;}
	}
}

int main()
{
   inputfile();
    int i,n,t;
    fast_sieve();
    Sd(t);
	//ans[0]=ans[1]=0;

   while(t--)
   {
	Sd(n);
	printf("%d\n",ans[n]);

   }
    return 0;
}
