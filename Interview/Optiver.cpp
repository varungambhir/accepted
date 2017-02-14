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

ll MOD = 1000000007LL;

class Shape {
public:
    virtual int GetArea() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    int height;
    int width;
public:
    Rectangle(int height, int width) {
        this->height = height;
        this->width = width;
    }
    int GetArea() {
        return round(this->height*this->width);
    }

};

class Triangle : public Shape {
private:
    int height;
    int width;
public:
    Triangle(int height, int width) {
        this->height = height;
        this->width = width;
    }
    int GetArea() {
        return round((this->height * this->width)/2.0);
    }

};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int r) {
        this->radius = r;
    }
    int GetArea();
};

int Circle::GetArea() {
    return round(double(3.14*this->radius*this->radius));
}

namespace mySpace
{
    void study();
    class Learn {};
}

void mySpace::study() {
    cout << "Study\n";
}

map<char,vector<char> > v;

int main(int argc, char const *argv[])
{
    Circle r(10);

    using namespace mySpace;
    study();


    return 0;
}