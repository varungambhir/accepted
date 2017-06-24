class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> > &a = grid;
        int m = a.size();
        if(!m) return 0;
        int n = a[m-1].size();
        if(!n) return 0;
        
        int dp[m+2][n+2];
        dp[0][0] = a[0][0];
        for(int i = 1 ; i < m ; i++) {
            dp[i][0] = dp[i-1][0] + a[i][0];
        }
        for(int j = 1; j < n ; j++) {
            dp[0][j] = dp[0][j-1] + a[0][j];
        }
        
        for(int i = 1; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                dp[i][j] =  min(dp[i-1][j], dp[i][j-1]) + a[i][j] ;
            }
        }
        return dp[m-1][n-1];
    }
};