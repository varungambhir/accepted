#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
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
#define present_vector(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
  template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
  template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
  #define trace(...)
#endif

ll MOD = 1000000007LL;



// https://www.careercup.com/question?id=5768685966852096


#define LEFT_DIR 10
#define RIGHT_DIR 20

#define UPD 1
#define DOWND 2
#define LEFTD 3 
#define RIGHTD 4

int grid[22][22];
int visited[22][22];
int r,c;
bool orig_dir[22][22][6];

bool isInside(int i,int j) {
  if(i >=1 && i <= r && j>=1 && j<=c)
    return true;
  else 
    return false; 
}

int rotateLeft(int dir) {
  if(dir == LEFTD)
    return DOWND;

  else if(dir == UPD)
    return LEFTD;

  else if(dir == RIGHTD)
    return UPD;

  else if(dir == DOWND)
    return RIGHTD;
}


int rotateRight(int dir) {
  if(dir == LEFTD)
    return UPD;

  else if(dir == UPD)
    return RIGHTD;

  else if(dir == RIGHTD)
    return DOWND;

  else if(dir == DOWND)
    return LEFTD;
}

int dfs(int i,int j ,int dir) {
  //trace(i,j);
  if(
     !isInside(i,j) || (visited[i][j] && orig_dir[i][j][dir])
     )
    return 0;

  int sum = 1;
  
  if(visited[i][j]) {

    orig_dir[i][j][dir] = true;
    sum = 0;
  }

  if( grid[i][j] ==  LEFT_DIR)
    dir = rotateLeft(dir);
  else if(grid[i][j] == RIGHT_DIR)
    dir = rotateRight(dir);

  visited[i][j] = true;

  if(dir == UPD)
    return sum + dfs(i-1,j,dir);

  else if(dir == RIGHTD)
    return sum + dfs(i,j+1,dir);

  else if(dir == DOWND)
    return sum + dfs(i+1,j,dir);

  else if(dir == LEFTD)
    return sum + dfs(i,j-1,dir);
}


inline void init(int i, int j ,int dir) {
  memset(visited,0, sizeof(visited));
  memset(orig_dir,0,sizeof(orig_dir));
  orig_dir[i][j][dir] = true;
}


/**
* https://www.careercup.com/question?id=5768685966852096
*/
int main(int argc, char const *argv[])
{
  BOOST;
  int t;
  cin >> t;
  while(t--) {
    cin >> r >> c;
    string s;
    memset(grid,0,sizeof(grid));
    FOR(i,1,r) {
      cin >> s;
      FOR(j,0,c-1) {

        if (s[j] == 'l')
          grid[i][j+1] = LEFT_DIR;
        
        else if(s[j] == 'r')
          grid[i][j+1] =  RIGHT_DIR;
      }
    }

    // TC O(r*(r*c)*c)
    int maxlen = 0;
    FOR(i,1,r) {
      FOR(j,1,c) {
        if(grid[i][j] != 0)
          continue;
        
        init(i,j,UPD);
        maxlen = max(maxlen,dfs(i,j,UPD));

        init(i,j,DOWND);        
        maxlen = max(maxlen,dfs(i,j,DOWND));

        init(i,j,LEFTD);
        maxlen = max(maxlen,dfs(i,j,LEFTD));
        
        init(i,j,RIGHTD);
        maxlen = max(maxlen,dfs(i,j,RIGHTD));
      }
    }
    cout << maxlen << endl;
  }
  return 0;
} 