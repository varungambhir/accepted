#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L 2*index
#define R 2*index+1
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

 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun

And you run and you run to catch up with the Sun but it's sinking
Racing around to come up behind you again
The Sun is the same in a relative way, but you're older
Shorter of breath and one day closer to death

Every year is getting shorter, never seem to find the time
Plans that either come to naught or half a page of scribbled lines
- Time, Pink Floyd*/



//https://kartikkukreja.wordpress.com/2016/01/30/bit-fiddling-exercise-that-grey-matter/
int main(int argc, char const *argv[])
{
    //1.Isolating the rightmost bit
    int x  = 90; //01011010;
    //-x 2's complement r^m - N
    // 00000010
    int ans = x & (-x); //00000010 2nd Bit set i.e. one after LSB
    cout << "rightmost bit : " << ans << endl;

    //2.Create a word with a single 1-bit at the pos. of the rightmost 0-bit
    // ~x bitwise 1's complement
    // single 1-bit at the position of the rightmost 0-bit.
    //if all 1's o/p 0
    //01011011 => 00000100
    x = 91; //01011011
    ans = (~x) & (x+1);
    cout << "single 1-bit at pos of rightmost 0-bit : " << ans << endl;
    //ANS = 4 i.e. 00000100 
    //(x+1) sets rightmost 0-bit and clears the 1's on its right 
    // ~x & (x+1) has at most 1 set bit - the rightmost 0-bit.
    //if x has all 1's,(x+1) causes an overflow of the 1-bit and 
    //result is all 0s
    
    //3.
    x = 88;//01011000 single 0-bit at rightmost 1 bit
    //ans    11110111
    ans = (~x) | (x-1);
    cout <<"single 0-bit at position o rightmost 1-bit : "<< ans <<endl;
    //(x-1) clears the rightmost 1-bit and sets the 0's on its right.
    //if x has all 0's ~x nd x-1 are all 1s so result is all 1's

    //4. Turn off the rightmost contiguous string of 1's
    //Ex 01011100 => 01000000

    x= 92;

    ans = ( (x & -x) + x ) & x;
    // x  = 01011100
    //-x  = 10100100
  //x & -x= 00000100 rightmost 1-bit isolated
//(x&-x)+x= 01100000 clears the rightmost contiguous
//ans     = 00000000

    /*5. Find the next higher number containing the same number of set bits. Ex: 01011100 => 01100011.

a ← x & -x

b ← a + x

r ← b | (((x ⊕ b) >> 2) / a)
*/

/*
#include <iostream>
#include <bitset>
using namespace std;

// used char for illustration, use int in practice
typedef unsigned char uint;
const unsigned int SIZE = sizeof(uint) * 8;

void printBitRepresentation(uint x) {
    cout << bitset<SIZE>(x) << endl; 
}

uint getNextHigherNumberContainingEqualSetBits(uint x) {
    if (x == 0) return 0;
    uint a = x & -x;
    uint b = a + x;
    uint r = b | (((x ^ b) >> 2) / a);
    return r;
}

void generateAllSubsets(uint start) {
    printBitRepresentation(start);
    for (uint cur = getNextHigherNumberContainingEqualSetBits(start); cur > start; cur = getNextHigherNumberContainingEqualSetBits(cur))
        printBitRepresentation(cur);
}

int main() {
    generateAllSubsets((1 << (SIZE-1)) - 1);
    return 0;
}*/

    return 0;
}