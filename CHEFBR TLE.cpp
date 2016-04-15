#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
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

int ans = 0;
int n;
int a[110];
int dp[110] = {0};

vector<int> s1;
stack<int> st;
int k = 0;
void verifyy()
{
    s1.clear();
    k++;
    FOR(i,1,n)
    if(dp[i] == 1)
        s1.push_back(a[i]);   
    
    while(!st.empty()) st.pop();
    
    
    FOR(i,0,s1.size()-1)
    {
        if(s1[i] < 0 )
        {
            st.push(-s1[i]);
        }
        else//s1[i] > 0
        {
            if(st.empty() == false)
            {
                if(st.top() == s1[i])
                    st.pop();
                else
                {
                    st.push(0);
                    break;
                }
            }
            else
            {
                st.push(0);
                break;
            }
        }
    }

    if(st.empty() == true)
    {
        ans++;
      /*  repstl(s1)
    {
        cout << *it << " ";
    }
    cout << endl;
    */
    }

    return;
}

void dfs(int index = 1 , int choose = 1 )//1 => choose , 0=> leave
{

    if( choose == 1)
        dp[index] = 1;
    else
        dp[index] = 0;

    if(index >= n)
    {
        verifyy();
        return;
    }
    else
    {
        dfs(index+1,1);
        dfs(index+1,0);
        return;
    }
}


int main(int argc, char const *argv[])
{
    BOOST;
    //int n;
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i];
    }
    ans = 1;//empty
    dfs(1,1);
    dfs(1,0);

    cout << ans << endl;
    //cout << k << endl;
    return 0;
}