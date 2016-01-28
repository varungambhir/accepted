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
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(all(c),x) != (c).end())
#define MAXN 100005
#define MOD 1000000007
int n,m;


int main(int argc, char const *argv[])
{
  BOOST;
  cin>>n>>m;
  int ans = 0;
  if(n == 1)
  {
    if(m > 2)
    {
      cout<<"1\n";
      cout<< n <<" "<< m << " 1 1\n"; 
    }
    else
    {
      cout<<0<<endl;
    }

    FOR(i,1,m+1)
    {
      cout<< n << " " << i << "\n";
    }

    cout<<"1 1\n";
  }
  else if (m == 1)
  {
    if(n>2)
    {
      cout<<"1\n";
      cout<< n <<" "<<m << " 1 1\n";
    }
    else
    {
      cout<<"0\n";
    }
    FOR(i,1,n+1)
    {
      cout<< i << " " << m << "\n";
    }
    cout<<"1 1\n"; 
  }
  else
  {
    if(n%2 == 0)
    {
      cout<<"0\n";
      FOR(i,1,n+1)
      {
        cout<< i <<" "<< 1 <<endl;
      }
      ROF(i,n,1)
      {
        if( i%2 == 0)
        {
          FOR(j,2,m+1)
          {
            cout<< i <<" " << j <<endl;
          }
        }
        else
        {
          ROF(j,m,2)
          {
            cout<< i <<" " << j <<endl;
          }
        }
      }
      cout<<"1 1\n"; 
    }

    else if (m%2 == 0)
    {
      cout<<"0\n";
      FOR(i,1,n+1)
      {
        cout<< i <<" "<< 1 <<endl;
      }
      FOR(i,2,m+1)
      {
        cout<< n <<" " << i <<endl;
      }
      ROF(i,m,2)
      {
        if( i%2 == 0)
        {
          ROF(j,n-1,1)
          {
            cout<<j<<" "<<i<<endl;
          }
        }
        else
        {
          FOR(j,1,n)
          cout<<j<<" "<<i<<endl;
        }
      }
      cout<<"1 1\n"; 
    }

    else
    {
      cout<<1<<endl;
      cout<<n<<" "<<m<<" 1 1\n";
      FOR(i,1,n+1)
      {
        if( i%2 != 0)
        {
          FOR(j,1,m+1)
          {
            cout<<i<<" "<<j<<endl;
          }
        }
        else
        {
          ROF(j,m,1)
          {
            cout<<i<<" "<<j<<endl;
          }
        }
      }
              cout<<"1 1\n";
    }

  }


  return 0;
}
