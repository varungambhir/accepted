#include<cstdio>
#include<cstring>
int main()
{
   int t,temp;
   char a[22];
   long long int b;
   int ans[][4]={ {0,0,0,0},
   {1,1,1,1},
   {2,4,8,6},
   {3,9,7,1},
   {4,6,4,6},
   {5,5,5,5},
   {6,6,6,6},
   {7,9,3,1},
   {8,4,2,6},
   {9,1,9,1} };
   scanf("%d",&t);
   while(t--)
   {
      scanf("%s %lld",a,&b);
      if(b==0)
      {
         printf("1\n");
         continue;
      }
      temp=a[strlen(a)-1]-'0';
      b=b%4;
      b = (b==0)?3: (b-1);
      printf("%d\n",ans[temp][b]);
   }
   return 0;
   }
