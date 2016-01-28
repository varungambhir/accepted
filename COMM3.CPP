#include<stdio.h>
int main(){
int t,r,x1,x2,x3,y1,y2,y3,count;
scanf("%d",&t);
while(t--){
    scanf("%d%d%d%d%d%d%d",&r,&x1,&y1,&x2,&y2,&x3,&y3);
    count=0;
    if( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2)<= r * r)
    count++;
    if((x3-x2) * (x3-x2) + (y3-y2) * (y3-y2) <= r * r)
    count++;
    if((x1-x3) * (x1-x3) + (y1-y3) * (y1-y3) <= r * r)
    count++;
    if(count>=2)
    printf("yes\n");
    else printf("no\n");
}
return 0;}
