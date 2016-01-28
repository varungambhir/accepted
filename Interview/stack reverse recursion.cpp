#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
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
#define MAXN 100010
#define MOD 1000000007
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define sn struct snode
struct snode
{
  char data;
  struct snode *next;
};
stack<int> s;

void insertAtBottom(stack<int> &it, int data)
{
  if(it.empty())
  {
    it.push(data);
  }
  else
  {
    int temp = it.top();
    it.pop();
    insertAtBottom(it, data);
    it.push(temp);
  } 
}

void reverse(stack<int> &it)
{
  if(it.empty()) return;
  int temp = it.top();
  it.pop();
  reverse(it);
  insertAtBottom(it, temp);
} 

int main(int argc, char const *argv[])
{
  FOR(i,0,10)
  {
    s.push(i);
    cout << i << " ";
  }
  cout << endl;
  cout << "top "<< s.top() << endl;

 reverse(s);

 FOR(i,0,10)
 {
    cout << s.top() << " ";
    s.pop();
 }

  return 0;
}