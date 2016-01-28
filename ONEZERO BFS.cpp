#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,n) for(int (i) = (a); (i) < (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define Sd(x) scanf("%d",&x)
#define f first
#define s second
#define repstl(v) for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << "\n"
#define MAX 1000005
#define MOD 1000000007
#define endl "\n"
typedef pair<int,int> pii;
queue<int> q;

int value[20010],parent[20010];
int temp, curr_state;

void bfs(int n)
{
    while(!q.empty())
    q.pop();
    q.push(1);
    parent[1]=0;

    while(!q.empty())
    {
        curr_state = q.front();
        q.pop();
        if(!curr_state)
        {
            stack<int> s;
            while(parent[curr_state]!=0)
            {
                s.push(value[curr_state]);
                curr_state = parent[curr_state];
            }
            s.push(1);
            while(!s.empty())
            {
                cout<<s.top();
                s.pop();
            }
            cout<<endl;
            break;
        }
        temp = (curr_state*10)%n;
        if(parent[temp]==-1)
        {
            q.push(temp);
            parent[temp] = curr_state;
            value[temp] =0;
        }
        temp = (curr_state*10 + 1)%n;
        if(parent[temp]==-1)
        {
            q.push(temp);
            parent[temp] = curr_state;
            value[temp] =1;

        }

    }
    return;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.in","r",stdin);
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(parent,-1,sizeof(parent));
        cin>>n;
        bfs(n);
    }
    return 0;
}
