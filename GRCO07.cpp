#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*node
#define R 2*node+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 2020
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
void func() {  printf("SORRY JOHN!\n"); }
int main(int argc, char const *argv[])
{

  int t;
  cin >> t;
  while(t--)
  {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(c == d)
    {
      if(c < a && c <= b)
      {
        FOR(i,1,a-c-1) cout << "1";
        FOR(i,1,c) cout <<"12";
        FOR(i,1,b-c) cout << "2";
        cout <<"1";
        cout << endl;
      }
      else if(c<=a && c < b)
      {
        cout <<"2";
        FOR(i,1,a-c) cout<<"1";
        FOR(i,1,c) cout << "12";
        FOR(i,1,b-c-1) cout <<"2";
        cout << endl;
      }
      else
        func();
    }
    else if( c == d-1)
    {
      if( c>=a || c>= b) func();
      else
      {
        cout<<"2";
        FOR(i,1,a-c-1) cout<<"1";
        FOR(i,1,c) cout << "12";
        FOR(i,1,b-c-1) cout << "2";
        cout <<"1" << endl;
      }
    }
    else if(c == d+1)
    {
      if(c > a || c > b) func();
      else
      {
        FOR(i,1,a-c) cout<<"1";
        FOR(i,1,c)   cout<<"12";
        FOR(i,1,b-c) cout<<"2";
        cout << endl;
      }
    }
    else
    {
      func();
    }
  }
  return 0;
}