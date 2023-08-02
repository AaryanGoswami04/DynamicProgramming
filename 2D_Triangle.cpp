/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 */
//https://leetcode.com/problems/triangle/description/
//Memoization: dp[row][col] stores min path sum from (row, col) to bottom most row
//TC: O(N*N); SC:O(N^2 + N)
int rec(int row, int col, int n,vector<vector<int>>& dp,  vector<vector<int>>& triangle){
        if(row == n-1) return triangle[row][col];
     
        if(dp[row][col] != INT_MAX) return dp[row][col];
           
        int left = triangle[row][col] + rec(row+1, col, n, dp, triangle);
        int right = triangle[row][col] + rec(row+1, col+1, n, dp, triangle);

        return dp[row][col] = min(left, right);
  }

//Tabulation: TC:O(N^2); SC:O(N^2)
int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp;

        for(int i=1; i<=n; i++){
            vector<int> temp(i,1e5);
            dp.push_back(temp);
        }

        //Set the last row of the dp vector with triangle[n-1][col]
        for(int col=0; col<n; col++) dp[n-1][col] = triangle[n-1][col];
         
        for(int row = n-2; row >= 0; row--)
        {
            for(int col = 0; col <= row; col++)
            {
                int left = dp[row+1][col] + triangle[row][col];
                int right = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(left, right);
            }
        }

        return dp[0][0];
    }

//Space optimisation: TC:O(N^2); SC:O(N)
  int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<int> nextRow(n);

    for(int col=0; col<n; col++) nextRow[col] = triangle[n-1][col];
         
    for(int row = n-2; row >= 0; row--)
      {
        vector<int> CurrRow (row+1);

        for(int col = 0; col <= row; col++)
          {
              int left = nextRow[col] + triangle[row][col];
              int right = nextRow[col+1] + triangle[row][col];

              CurrRow[col] = min(left, right);
          }
         nextRow = CurrRow;
      }
    return nextRow[0];
    }
