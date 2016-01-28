#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10004;
int MOD = 1000000007, ctr = 0, depth = (1<<14), firpos[MAXN], lpos[MAXN], seg[(1<<15)];
vector <int> G[MAXN];
void dfs(int pos, int par)
{
    firpos[pos] = ctr;
    for (int i = 0; i < G[pos].size(); ++i)
    {
        if(G[pos][i] != par)
        {
            ctr++;
            dfs(G[pos][i],pos);
        }
    }
    lpos[pos] = ctr;
}
void point_update(int pos, long long int val)
{
    while(pos)
    {
        seg[pos] = (seg[pos] + val)%MOD;
        pos/=2;
    }
}
int range_query(int root, int lmost, int rmost, int u, int v)
{
    if(u <= lmost && rmost <= v)
        return seg[root];
    int lval = 0, rval = 0, mid = (lmost+rmost)/2;
    if(u <= mid)
        lval = range_query(2*root, lmost, mid, u, v);
    if(mid < v)
        rval = range_query(2*root + 1, mid+1, rmost, u, v);
    return (lval+rval)%MOD;
}
vector < vector <long long int> > mat_mult(vector < vector <long long int> > &A, vector < vector <long long int> > &B)
{
    vector < vector <long long int> > ans(2, vector <long long int> (2,0));
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                ans[i][j] = (ans[i][j] + A[i][k]*B[k][j])%100000ll;
            }
        }
    }
    return ans;
}
vector < vector <long long int> > mat_power(vector < vector <long long int> > &A, int b)
{
    if(b == 1)
        return A;
    vector < vector <long long int> > ans = mat_power(A,b/2);
    ans = mat_mult(ans,ans);
    if(b%2)
        ans = mat_mult(ans,A);
    return ans;
}
int fibo(int n)
{
    if(n%2)
        return 0;
    n/=2;
    if(n <= 1)
        return 1;
    vector < vector <long long int> > A(2, vector <long long int> (2,1));
    A[1][1] = 0;
    A = mat_power(A,n-1);
    int ans = (A[0][0]+A[0][1])%100000;
    return ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(0);
    int n,q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n-1; ++i)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for (int i = 1; i <= n; ++i)
    {
        point_update(depth+firpos[i], 1);
    }
    while(q--)
    {
        int qtype;
        scanf("%d", &qtype);
        if(qtype)
        {
            int v;
            scanf("%d", &v);
            printf("%d\n", range_query(1, depth, 2*depth - 1, depth+firpos[v], depth+lpos[v]));
        }
        else
        {
            int v,m;
            scanf("%d %d", &v, &m);
            long long int to_add = fibo(m);
            to_add = (to_add*((long long int)m))%MOD;
            point_update(depth+firpos[v],to_add);
        }
    }
    return 0;
} 