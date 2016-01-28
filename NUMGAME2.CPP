#include<stdio.h>
int main(){
long int n,t;
scanf("%ld",&t);
while(t--){
scanf("%ld",&n);
if(n%4==1)
printf("ALICE\n");
else printf("BOB\n");
}
return 0;
}
