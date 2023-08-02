/*Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.*/
//https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

//Memoization: dp[i][j] stores min sum of req. falling path from (i,j) to last row
//TC: O(N^3); SC:O(N^2 + N)
  int rec(int row, int col, int n, vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(row == n-1) return grid[row][col];

        if(dp[row][col] != INT_MAX) return dp[row][col];  

        for(int i=0; i<n; i++){
            if(i == col) continue;

            dp[row][col] = min(dp[row][col], grid[row][col] + rec(row+1, i, n, dp, grid));
       }

       return dp[row][col];
  }

//Tabulation: TC:O(N^2 + N); SC:O(N^2)
 int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), ans=INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));

        for(int col=0; col<n; col++) //Set base cases
            dp[n-1][col] = grid[n-1][col];
        
        for(int row=n-2; row>=0; row--)
        {
            for(int col=0; col<n; col++)
            {

                for(int i=0; i<n; i++){
                    if(i == col) continue;

                    dp[row][col] = min(dp[row][col], grid[row][col] + dp[row+1][i]);
                }
            }
       }

        for(int col=0; col<n; col++)  ans = min(ans, dp[0][col]);
     
        return ans;
    }

//Space optimisation: SC:O(N)
int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), ans=INT_MAX;
        vector<int> nextRow(n);

        for(int col=0; col<n; col++) //Set base cases
            nextRow[col] = grid[n-1][col];
    
        for(int row=n-2; row>=0; row--)
        {
            vector<int> CurrRow (n, INT_MAX);
            for(int col=0; col<n; col++)
            {

                for(int i=0; i<n; i++){
                    if(i == col) continue;

                    CurrRow[col] = min(CurrRow[col], grid[row][col] + nextRow[i]);
                }
            }
            nextRow = CurrRow;
       }

        for(int col=0; col<n; col++)  ans = min(ans, nextRow[col]);
        
        return ans;
  }  
