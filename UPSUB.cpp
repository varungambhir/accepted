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
#define repstl(v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define MAXN 1010
#define MOD 1000000007
 
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
string s;
int arr[120];
set<string> AnsSET;

void rec(int arrInd, int index, string T,int maxlen)
{
  //debug(T);
  if(T.size() == maxlen)
  {
    AnsSET.insert(T);
    return;
  }

  FOR(i,index,s.size())
  {
    if(T[T.size() -1] <= s[i] && arr[i] == arrInd )
    {
      string temp = T;
      temp.push_back(s[i]);
      rec(arrInd+1,i+1,temp,maxlen);
    }
  }
  return;
}

int main(int argc, char const *argv[])
{
  BOOST;
  int mxg,t;
  cin >> t;
  while(t--)
  {    
    cin >> s;
    int mxl;
    mxg = 0;
    AnsSET.clear();
    memset(arr,0,sizeof(arr));
    int len = s.size();
    FOR(i,0,len)
    {
      arr[i] = 1;
      mxl = 0;

      for(int j = i-1; j>=0 ; j--)
      {
        if(s[i] >= s[j])
          mxl = max(mxl,arr[j]);
      }
      arr[i] += mxl;
      mxg = max(mxg,arr[i]);
      //debug(arr[i]);
    }

    FOR(i,0,len)
    {
      if(arr[i] == 1)//st
      {
        string temp;
        temp.push_back(s[i]);//single char string
        rec(2,i+1,temp,mxg);
        //  ^ arr[i]==2
      }
    }

    repstl(AnsSET)
    {
      cout << (*it) << "\n";
    }

  }

  return 0;
}