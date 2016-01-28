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
#define L 2*stindex
#define R 2*stindex+1
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
 /*Tired of lying in the sunshine, Staying home to watch the rain
You are young and life is long, And there is time to kill today
And then one day you find, 10 years have got behind you
No one told you when to run, You missed the starting gun
- Time, Pink Floyd*/
#define MAXN 1010
#define MOD 1000000007
const double eps=1e-8;
const double inf=1e20;
const double pi=acos(-1.0);
const int maxp=1111;
int dblcmp(double d){
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline double sqr(double x){return x*x;}
struct point {
    double x,y;
    point(){}
    point(double _x,double _y):
    x(_x),y(_y){};
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void output(){
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(point a)const{
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const{
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len(){
        return hypot(x,y);
    }
    double len2(){
        return x*x+y*y;
    }
    double distance(point p){
        return hypot(x-p.x,y-p.y);
    }
    point add(point p){
        return point(x+p.x,y+p.y);
    }
    point sub(point p){
        return point(x-p.x,y-p.y);
    }
    point mul(double b){
        return point(x*b,y*b);
    }
    point div(double b){
        return point(x/b,y/b);
    }
    double dot(point p){
        return x*p.x+y*p.y;
    }
    double det(point p){
        return x*p.y-y*p.x;
    }
}a[maxp];
struct line {
    point a,b;
    line(){}
    line(point _a,point _b){
        a=_a;
        b=_b;
    }
    int relation(point p){
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
};

int w[maxp];
int n;

int main(){
    int ans=0;
    while (scanf("%d",&n)==1){
        for (int i=1;i<=n;++i){
            a[i].input();
            scanf("%d",&w[i]);
        }
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j){
                int p1=0,p2=0;
                line t(a[i],a[j]);
                for (int k=1;k<=n;++k){
                    if (i==k || j==k) continue;
                    if (t.relation(a[k])==1) p1+=w[k];
                    else p2+=w[k];
                }
                ans=max(ans,min(p1+w[i],p2));
                ans=max(ans,min(p1,p2+w[i]));
                ans=max(ans,min(p1+w[j],p2));
                ans=max(ans,min(p1,p2+w[j]));
                ans=max(ans,min(p1,p2+w[i]+w[j]));
                ans=max(ans,min(p1+w[i]+w[j],p2));
                ans=max(ans,min(p1+w[i],p2+w[j]));
                ans=max(ans,min(p1+w[j],p2+w[i]));
            }
        cout << ans << "\n";
    }
    return 0;
}
