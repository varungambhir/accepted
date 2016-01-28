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
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 10000005
#define MOD 1000000007

bool prime[MAXN]={0};
//int num[2][MAXN]={0};
std::vector<int> p;
void seive()
{
    for(ll i =2; i<= 3165 ;i++)
    {
        if(!prime[i])
            p.pb(i);
        else
            continue;
        for(ll j = i; i*j<=MAXN ; j += i)
        {
            prime[i*j] = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    //BOOST;
    seive();
    int t,n2,n;
    SD(t);
    int len = p.size();
    while(t--)
    {
        SD(n2);
        n = n2;
        int cnt,even,odd;
        even=odd=0;
        for(int i = 0 ; i<len && p[i]*p[i]<=n; i++)
        {
            if(p[i]>n)
                break;
            if( n%p[i] == 0)
            {
                cnt = 0;
                while(n%p[i]==0)
                {
                    n /= p[i];
                    cnt++;
                }

                if(cnt!=0 && (cnt%2 == 0))
                    even++;
                else
                    odd++;
            }    
        }

        if(n!=1)
            odd++;
        if(even > odd)
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
    return 0;
}