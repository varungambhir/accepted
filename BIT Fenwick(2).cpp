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

int MaxVal = 100;

int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx = idx - ( idx & (-idx) );
    }
    return sum;
}


void update(int idx, int val)
{
    while(idx <= MaxVal)
    {
        tree[idx] += val;
        idx = idx + (idx & (-idx));
    }
}


int readSingle(int idx) //calculate the single frequency at idx
{
    int sum = tree[idx]; //sum will be decreased

    if(idx > 0)
    {
        int z = idx - (idx & (-idx)); // z is predecessor after remove last 1 digit

        idx--; // or equal to y = idx - 1

        while(idx != z)//y will become z
        {
            sum -= tree[idx];
            idx -= (idx & (-idx));
        //substruct tree frequency which is b/w y and the "same path"
        }
    }
    return sum;
}


void scale(int c)
{
    FOR(i,1,MaxVal)
    {
     //   update( i , -(c-1)*readSingle(i)/c ); //O(Maxval * log(MaxVal))
        tree[i] /= c; // O(MaxVal)
    }
}



//if in tree exists more than one index with a same
// cumulative frequency, this is procedure will return
// some of them (we don't know which one)

//bitMask - initialy, it is the greates bit of MaxVal
//bit mask store interval which should be searched

int find(int cumFre)
{
    int idx = 0; //this var is result of function
    while( (bitMask != 0) && (idx < Maxval) )//overflow prevent
    {
        int tIdx = idx + bitMask;// we make midpoint of the interval
        if( cumFre == tree[tIdx] )//if it is equal,we just return
            return tIdx;
        else if ( cumFre > tree[tIdx])
        {
            //if tree freq "can fit" into cumFre,
            //the  include it

            idx = tIdx;// update index'
            cumFre -= tree[tIdx];
        }
        bitMask >>= 1; //half the current interval
    }

    if(cumFre != 0)//may be given cumulative frequence
        return -1;
    else
        return idx;
}

// if in tree there exists more than one index witha a same
// cumulative frequency, this procedure will return
// the greatest one
int findG(int cumFre)
{
    int idx = 0;

    while((bitMask != 0) && (idx < Maxval))
    {
        int tIdx  = idx + bitMask;
        if( cumFre >= tree[tIdx])
        {
            //if current cummulative frequency is equal to cumFre
            //we are still looking for higher index(if exists)
            idx = tIdx;
            cumFre -= tree[tIdx];
        }
        bitMask >>= 1; 
    }
    if(cumFre != 0)
        return -1;
    else
        return idx;
}


int main(int argc, char const *argv[])
{

    return 0;
}