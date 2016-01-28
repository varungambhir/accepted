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
#define MAXNN 510
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
string F[] = {"1", "3", "9", "27", "81", "243", "729", "2187", "6561", "19683", "59049", "177147", "531441", "1594323", "4782969", "14348907", "43046721", "129140163", "387420489", "1162261467", "3486784401", "10460353203",
            "31381059609", "94143178827", "282429536481", "847288609443", "2541865828329", "7625597484987", "22876792454961", "68630377364883", "205891132094649", "617673396283947", "1853020188851841", "5559060566555523", "16677181699666569",
            "50031545098999707", "150094635296999121", "450283905890997363", "1350851717672992089", "4052555153018976267", "12157665459056928801", "36472996377170786403", "109418989131512359209", "328256967394537077627", "984770902183611232881",
            "2954312706550833698643", "8862938119652501095929", "26588814358957503287787", "79766443076872509863361", "239299329230617529590083", "717897987691852588770249", "2153693963075557766310747", "6461081889226673298932241", "19383245667680019896796723",
            "58149737003040059690390169", "174449211009120179071170507", "523347633027360537213511521", "1570042899082081611640534563", "4710128697246244834921603689", "14130386091738734504764811067", "42391158275216203514294433201", "127173474825648610542883299603",
            "381520424476945831628649898809", "1144561273430837494885949696427", "3433683820292512484657849089281", "10301051460877537453973547267843", "30903154382632612361920641803529", "92709463147897837085761925410587"};
int main() {

   inputfile();
   unsigned long long n;
   while(scanf("%llu",&n)==1 && n!=0)
   {
    n--;
    printf("{ ");
    int c=0;
    bool lol=0;
    while(n>0)
    {
        if(n%2==1)
        {
            if(lol)printf(",");
            else lol=1;
            printf(" %s",F[c].c_str());//intersesting
        }
        c++;
        n=n/2;
    }
    printf(" }\n");
   }
return 0;
}
