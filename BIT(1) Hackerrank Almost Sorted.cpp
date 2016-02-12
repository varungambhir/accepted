#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/

#define MOD 1000000007
#define MAXN 1234567

map<int,int> m,cpy;
int a[1000010];
int main(int argc, char const *argv[])
{
  BOOST;
  memset(a,-1,sizeof(a));
  int n;
  cin >> n;
  FOR(i,1,n)
  {
    cin >> a[i];
    m[a[i]] = i;
  }
  if(n == 2)
  {
    if(a[1] <= a[2])
    {
      cout << "no\n";
      return 0;
    }
    else
    {
      cout<<"yes\nswap 1 2\n";
      return 0;
    }
  }

  bool k = 1;
  FOR(i,2,n)
  {
    if(a[i] < a[i-1])
    {
      k = 0;
      break;
    }
  } 

  if(k) { cout << "yes\n" ; return 0; }


  int ii,jj;
  ROF(i,n,2)
  {
    if(a[i] < a[i-1])
    {
      ii = i;
      int  j =i-1;
      while(j>=1 && a[i] < a[j])
        j--;
      jj = j+1;
      break;
    }
  }

  swap(a[ii],a[jj]);
  bool c = 1;
  FOR(i,2,n)
  {
    if(a[i] < a[i-1])
    {
      c = 0 ;
      break;
    }
  }
  if(c)
  {
    cout << "yes\nswap " << min(ii,jj) << " " << max(ii,jj)  <<endl;
    return 0;
  }

  sort(a+1,a+n+1);
  set<int> s1;
  FOR(i,1,n)
  {
    cpy[a[i]] = i;
    if(m[a[i]] != cpy[a[i]])
      s1.insert(m[a[i]] + cpy[a[i]]);
  }

/*
  repstl(m)
  {
    cout << it->F << " " << it->S << endl;
  }
  cout <<"---\n";
  repstl(cpy)
  {
    cout << it->F << " " << it->S << endl;
  }
*/
  if(s1.size() != 1)
  {
    cout <<"no\n";
    return 0;
  }


  FOR(i,1,n)
  {
    if(m[a[i]] != cpy[a[i]])
    {
      ii = i;
      break;
    }
  }

  //trace3(m[a[ii]],ii,cpy[a[ii]]);

  ii = min(m[a[ii]],cpy[a[ii]]);
  jj = max(m[a[ii]],cpy[a[ii]]);

  cout <<"yes\nreverse " << ii << " " << jj << endl;



  return 0;
}