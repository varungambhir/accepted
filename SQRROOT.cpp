#include <cstdio>
#include <cstring>
#define MAX_LEN 802
#define END 'A'
 
 void subtract(char* sum, int sumLen, char* difference, int diffLen) 
 {
 
  for(int i=0;i < diffLen;i++) 
  {
  int diffIdx = diffLen -i -1;
  int sumIdx = sumLen -i -1;
   char digitToSubtract = difference[diffIdx];
   if(sum[sumIdx] < digitToSubtract) 
    {
  	  sum[sumIdx-1] -= 1;
   	  sum[sumIdx] += 10;
	}  
	sum[sumIdx] -= digitToSubtract;
  }
 for(int i=sumLen - 1;i >= 0;i--)
  {
   if(sum[i] < 0) {
    sum[i-1] --;
    sum[i] += 10;
   					}
  }

 }

 void divideBy2(char* sum, int sumLen) 
 {
  for(int i=0; i<sumLen; i++) 
  {
   sum[i+1] += (sum[i] % 2)*10;
   sum[i] /= 2;
  }
 }
 
 void add(char* sum, int sumLen, char* difference, int diffLen, char* diffPlusDiv) 
 { 
  for(int i=0;i<diffLen;i++) 
 {
   diffPlusDiv[sumLen -1 -i] = sum[sumLen -1 -i] + difference[diffLen -1 -i];
 }

  for(int i=diffLen;i<sumLen;i++) 
 {
   diffPlusDiv[sumLen -1 -i] = sum[sumLen -1 -i];
 }

  for(int i=sumLen-1;i>0;i--) 
  {
   diffPlusDiv[i-1] += diffPlusDiv[i] / 10;
   diffPlusDiv[i] %= 10;
  }
  diffPlusDiv[sumLen] = END;
 }
 
 void printOut(char* sum)
 {
  int start = 0;
  while(sum[start] == 0) {
   start++;
  }
 
  int i = start;
  while(i<MAX_LEN) 
  {
   if(sum[i] == END) {
    break;
   }
   printf("%c", sum[i] + '0');
   i++;
  }
  printf("\n");
 }
 
 int reduce(char* toReduce) {
  int i=0;
 
  while(i<MAX_LEN) {
   if(toReduce[i] > 0) {
    toReduce[i] -= '0';
   } else {
    break;
   }
   i++;
  }
 
  toReduce[i] = END;
  return i;
 }
 
 int main(int argc, char** argv) {
 
  char sum[MAX_LEN+1]; 
  char difference[MAX_LEN+1]; 
  char diffPlusDiv[MAX_LEN+1];
 
  memset(sum, 0, MAX_LEN+1);
  memset(difference, 0, MAX_LEN+1);
  memset(diffPlusDiv, 0, MAX_LEN+1);
 int t;
 scanf("%d",&t);
  while(t--)
  scanf("%s",sum);
  scanf("%s", difference);
 
   int sumLen = reduce(sum);
   int diffLen = reduce(difference);
   subtract(sum, sumLen, difference, diffLen);
   divideBy2(sum, sumLen);
   add(sum, sumLen, difference, diffLen, diffPlusDiv);
 
   printOut(diffPlusDiv);
   printOut(sum);
 
   memset(sum, 0, MAX_LEN+1);
   memset(difference, 0, MAX_LEN+1);
} 
 return 0;
 }