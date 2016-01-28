#include<stdio.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
    int n,i;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    long long ans=0;
    for(i=0;i<n;i++)
        if (s[i]=='1');
    ans++;
    printf("%lld\n",ans*(ans+1)/2);
        }
return 0;
}
