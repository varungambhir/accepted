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
/*
Dreamoon has a string s and a pattern string p. He first removes exactly x characters from s obtaining string s' as a result. Then he calculates  that is defined as the maximal number of non-overlapping substrings equal to p that can be found in s'. He wants to make this number as big as possible.

More formally, let's define  as maximum value of  over all s' that can be obtained by removing exactly x characters from s. Dreamoon wants to know  for all x from 0 to |s| where |s| denotes the length of string s.

Input
The first line of the input contains the string s (1 ≤ |s| ≤ 2 000).

The second line of the input contains the string p (1 ≤ |p| ≤ 500).

Both strings will only consist of lower case English letters.

Output
Print |s| + 1 space-separated integers in a single line representing the  for all x from 0 to |s|.

Sample test(s)
input
aaaaa
aa
output
2 2 1 1 0 0
input
axbaxxb
ab
output
0 1 1 2 1 1 0 0
Note
For the first sample, the corresponding optimal values of s' after removal 0 through |s| = 5 characters from s are {"aaaaa", "aaaa", "aaa", "aa", "a", ""}.

For the second sample, possible corresponding optimal values of s' are {"axbaxxb", "abaxxb", "axbab", "abab", "aba", "ab", "a", ""}.

*/
int cost[MAXN];
int to[MAXN];
bool can[MAXN] = {0};
int dp[MAXN][MAXN];
int n,m;

int rec(int index , int deletes) //deletes no.
{
  if(index >=n )
  {
    if(deletes == 0)
      return 0;
    else
      return INT_MIN;
  } 
  if(dp[index][deletes] != -1)
    return dp[index][deletes];

  int ans = rec(index+1 , deletes); // skip
  //delete nd move 
  if(deletes)
    ans = max(ans, rec(index+1,deletes-1) );
  // use and move
  if(can[index] && cost[index] <= deletes)
    ans = max (ans , 1 + rec(to[index], deletes - cost[index])
               );
  dp[index][deletes] = ans;

  return ans;

}

int main(int argc, char const *argv[])
{
  string a,b;
  cin >> a >> b;
  n = a.size();
  m = b.size();

  FOR(i,0,n-1)
  {
    int j,k,c;
    if(a[i] != b[0]) continue;
    j = c  = 0;
    for(k = i; k < n && j < m; ++k)
    {
      if(a[k] == b[j])
        j++;
      else
        c++;
    }
    if(j == m)
    {
      can[i] = true;
      to[i] = k;
    }

    cost[i] = c; //deletions from i to to[i] when can i = true
  }
  memset(dp,-1,sizeof(dp));
  FOR(i,0,n)
  {
    cout << rec(0,i) << " ";
  }
  cout << endl;

  return 0;
}