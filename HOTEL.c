#include<stdio.h>
int main(){
int t,time,i,c,maxc,n;
scanf("%d",&t);
while(t--){
    maxc=0;
scanf("%d",&n);
    int a[n],d[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    scanf("%d",&d[i]);
    for(time=1;t<=1000;time++){
    c=0;
    for(i=0;i<n;i++){
     if(a[i]<=time&&time<d[i])
        c++;    }
         if(c>maxc)
        maxc=c;
    }

    printf("%d\n",maxc);
}
return 0;}
