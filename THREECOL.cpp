#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>
#include <climits>
#include <cctype>
#include <cassert>
#include <iterator>
#include <complex>
//#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<=(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define all(c) c.begin(), c.end()
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define cpresent_vector(c,x) (find(all(c),x) != (c).end())
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define matrix vector< vector<ll> >
//vector< vector<int> >Matrix(N, vector<int>(M,0));
#define gc getchar_unlocked
#define MAXNN 1000010
#define mod 1000000007
inline void inputfile() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
}
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void scanintll(long long int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
char word[20000];
int kid[20000][3], mini[20000][3], maxi[20000][3], got[20000][3], test_id;

void rec(int x, int c)
{
    if (got[x][c] == test_id) return;
    got[x][c] = test_id;
    for (int i = 0; i < word[x]-'0'; i++)
        for (int j = 0; j < 3; j++)
            rec(kid[x][i], j);

    mini[x][c] =-1 ;
    maxi[x][c] = 1<<30;

    if (word[x] == '0') {
        mini[x][c] = maxi[x][c] = (c == 0);
    } else if (word[x] == '1') {
        for (int lc = 0; lc < 3; lc++) {
            if (lc == c) continue;
            mini[x][c] =max(mini[x][c], mini[kid[x][0]][lc] + (c == 0));
            maxi[x][c] =min(maxi[x][c],maxi[kid[x][0]][lc] + (c == 0));
        }
    } else {
        for (int lc = 0; lc < 3; lc++)
        for (int rc = 0; rc < 3; rc++) {
            if (lc == c || rc == c || lc == rc) continue;
            mini[x][c] =max(mini[x][c], mini[kid[x][0]][lc] + mini[kid[x][1]][rc] + (c == 0));
            maxi[x][c] =min(maxi[x][c],maxi[kid[x][0]][lc] + maxi[kid[x][1]][rc] + (c == 0));
        }
    }
}

int pos;
void parse()
{
    int x = pos;
    int c = word[x] - '0';
    pos++;
    for (int i = 0; i < c; i++) {
        kid[x][i] = pos;
        parse();
    }
}

int main()
{
    inputfile();
    int T;
    scanf("%d", &T);

    for (int cs = 1; cs <= T; cs++) {
        test_id = cs;
        scanf(" %s", word);
        pos = 0;
        parse();

        rec(0, 0);
        rec(0, 1);
        rec(0, 2);
        printf("%d %d\n",
            max(mini[0][0],max(mini[0][1], mini[0][2])),
            min(maxi[0][0],min(maxi[0][1], maxi[0][2]))
            );
    }
}
