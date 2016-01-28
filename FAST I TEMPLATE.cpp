#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
 
typedef long long LL;
typedef double DB;
 
#define PII pair<int,int>
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
 
#define INF 0x7f7f7f7f
#define MAXN 100005
 
inline char _getchar()
{
    char ch;
    for (ch = getchar(); ch <= 32; ch = getchar());
    return ch;
}
 
template <class T> inline void read(T&x)
{
    bool f = false; char ch;
    for (ch = getchar(); ch <= 32; ch = getchar());
    if (ch == '-') f = true, ch = getchar();
    for (x = 0; ch > 32; ch = getchar()) x = x * 10 + ch - '0';
    if (f) x = -x;
}
 
template <class T> inline void read(T&x, T&y)
{
    read(x);
    read(y);
}
 
template <class T> inline void read(T&x, T&y, T&z)
{
    read(x);
    read(y);
    read(z);
}
 
template <class T> inline void write(T x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x < 10)
        putchar(x + '0');
    else
        write(x / 10), putchar(x % 10 + '0');
}
 
template <class T> inline void write_(T x)
{
    write(x);
    putchar(' ');
}
 
template <class T> inline void writeln(T x)
{
    write(x);
    puts("");
}
 
template <class T> inline void writeln(T x, T y)
{
    write_(x);
    writeln(y);
}
 
template <class T> inline void writeln(T x, T y, T z)
{
	write_(x);
    write_(y);
    writeln(z);
}
 
//----------------I/O Template-------------------
 
string name[10]={"Dhaval","Shivang","Bhardwaj","Rishab","Maji",
"Gaurav","Dhruv","Nikhil","Rohan","Ketan"};
 
int a[10]; bool f[10]; 
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	for (int i = 0; i < 10; i ++) read(a[i]);
	memset(f, true, sizeof(f));
	for (int i = 0; i < 10; i ++)
		if (i & 1)
		{
			int v = 1000000, x;
			for (int j = 0; j < 10; j ++)
				if (f[j])
				if (a[j] < v)
					v = a[j], x = j;
			f[x] = false;
			cout<<name[x]<<endl;
		} else {
			int v = 0, x;
			for (int j = 0; j < 10; j ++)
				if (f[j])
				if (a[j] > v)
					v = a[j], x = j;
			f[x] = false;
			cout<<name[x]<<endl;
		}
	return 0;
}