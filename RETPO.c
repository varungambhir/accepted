#include <cstdio>
#include <algorithm>
int main(){
long t;
long long x,y,a,ord,c;
scanf("%ld",&t);
while(t--){
scanf("%lld%lld",&x,&y);
x=abs(x);
y=abs(y);
a=ord=c=0;
while(a!=x || ord!=y){
    if(c%2==0){
            c++;
          if(ord<y)
              ord++;
          else
            ord--;
        }
    else{ c++;
            if(a<x)
            a++;
            else
                a--;
        }
}
printf("%lld\n",c);
}
return 0;
}
