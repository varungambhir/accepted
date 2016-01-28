#include<stdio.h>
int main(){
int r,t;
long p;
scanf("%d",&t);
while(t--){
r=0;
scanf("%ld",&p);
while(p>2048){
r++;
p-=2048;
}
while(p>0){
if(p%2==1)
r++;
p/=2;
}
printf("%d\n",r);
}
return 0;
}
