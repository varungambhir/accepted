class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(!m) return 0;
        int n = dungeon[m-1].size();
        if(!n) return 0;
        
        vector<vector<int>> &a = dungeon;
        int dp[m+3][n+3];
        
        dp[m-1][n-1] = (dungeon[m-1][n-1] >= 0) ? 1 : (1+abs(dungeon[m-1][n-1]) );
        
        //last col
        for(int i = m-2;  i>=0 ; i--) {
            dp[i][n-1] = dp[i+1][n-1] - dungeon[i][n-1];
            if(dp[i][n-1] < 1) {
                dp[i][n-1] = 1;
            }
            
        }
        
        //last row
        for(int i = n-2;  i>=0 ; i--) {
            dp[m-1][i] = dp[m-1][i+1] - dungeon[m-1][i];
            if(dp[m-1][i] < 1) {
                dp[m-1][i] = 1;
            }
        }
        
        for(int i = m-2 ; i >= 0 ; i--) {
            for(int j = n-2 ; j >= 0 ; j--) {
                int temp = min(dp[i+1][j] , dp[i][j+1]);
                temp -= dungeon[i][j];
                dp[i][j] = temp < 1 ? 1 : temp;
            }
        }
        return dp[0][0];
    }
};