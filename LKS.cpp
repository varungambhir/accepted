#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


// Weight DP
// Complexity: O(nW)
// F[a] := maximum value for weight a
// Top Down Approach
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
int knapsack(vector<int> v, vector<int> w, int W) {
  int n = v.size();
  vector<int> F(W+1);
  for (int i = 0; i < n; ++i)
    for (int a = W; a >= w[i]; --a)
      F[a] = max(F[a], F[a-w[i]] + v[i]);
  return F[W];
}

int main() {
  int W, n;
  scanf("%d %d", &W, &n);
  vector<int> v(n), w(n);
  for (int i = 0; i < n; ++i) 
    scanf("%d %d", &w[i], &v[i]);
  printf("%d\n", knapsack(v, w, W));
}