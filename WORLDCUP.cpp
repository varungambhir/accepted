#include <bits/stdc++.h>
using namespace std ;
#define P first
#define Q second
#define pb push_back
#define mp make_pair
typedef long long LL; 
typedef pair < int , int > ii ;
LL mod = 1e9 + 7 ;
typedef vector < int > vi ;
int r,b,w ;
LL dp[303][1822][13] ;
int diff []  = { 4, 6 , 0 , 0 } ;
 
int main(){
 memset ( dp , 0 ,sizeof dp) ;
 int i , j, k , l;
 
 dp[1][0][1] = dp[1][4][0] = dp[1][6][0] = dp[1][0][0] = 1 ;
 for ( i = 1 ; i <= 300 ; i++)
 for ( j = 0 ; j <= 1800 ; j++)
 {
      for ( k = 0 ; k <= 9 ; k++)
      for ( l = 0 ; l < 4 ; l++)
      { 
           if( l < 3)
           dp[i+1][j+diff[l]][k] += dp[i][j][k] , dp[i+1][j+diff[l]][k] %= mod ;
           else
           dp[i+1][j][k+1] += dp[i][j][k] , dp[i+1][j][k+1] %= mod ;
           
          
      }
 }
 
   
 int test ;
 cin >> test ;
 while ( test -- ){
      cin >> r >> b >> w ; 
      if( r%2 == 1 || r > 1800){
          cout <<"0\n"; continue ;
      }
      LL ans  =  0 ;
      for ( i = 0 ; i <= w ; i++)
      ans += dp[b][r][i] , ans %= mod ;
      cout << ans <<"\n" ;
 }
 
    
    
    
    return   0 ;
} 