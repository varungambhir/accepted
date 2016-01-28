#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long  long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
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
#define MAX 100010
#define mod 1000000007

int arr[3500];
int main()
{
  inputfile();
  cpp_input();

int n,k1,k2;

int a[12],b[12];

queue<int> q1 , q2;

int upperbound = 200;
int cnt = 0;

cin>>n;
cin>>k1;

FOR(i,0,k1)
{
  cin>>a[i];
  q1.push(a[i]);
}

cin>>k2;
FOR(i,0,k2)
{
  cin>>b[i];
  q2.push(b[i]);
}

int q1_top , q2_top;
while(!q1.empty() && !q2.empty() && cnt<=400)
{
  q1_top = q1.front();
  q2_top = q2.front();
  q1.pop();
  q2.pop();
  cnt++;
  if( q1_top > q2_top)
  {
    q1.push(q2_top);
    q1.push(q1_top);
  }
  else
  {
   q2.push(q1_top);
   q2.push(q2_top);
  }
}

int winner;
if(cnt>400)
{
  cout<<"-1\n";
}
else if(q1.empty())
{
 cout<<cnt<<" "<<"2\n";
}
else if(q2.empty())
{
 cout<<cnt<<" "<<"1\n";
}

  return 0;
}
