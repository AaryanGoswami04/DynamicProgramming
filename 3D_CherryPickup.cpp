// https://leetcode.com/problems/cherry-pickup-ii/
/*You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.*/

//Recursion: TC:O(3^N * 3^N); SC:O(N)
//Since both robots reach a row simultaneously, only one state is used to denote row idx
int rec(int r, int c1, int c2, int n, int m, vector<vector<int>>& grid){
        if(c1 < 0 or c2 < 0 or c1 >= m or c2 >= m) return INT_MIN;

        if(r == n-1){ //Both robots have reached last row
            if(c1 == c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }

        //explore all possible paths of both robots simultaneously
        int maxi=0;

        for(int dc1=-1; dc1<=1; dc1++){

            for(int dc2=-1; dc2<=1; dc2++){
            
                int val = (c1 == c2) ? grid[r][c1] : grid[r][c1]+grid[r][c2]; //Determining if both robots are on the same cell or not
                val += rec(r+1, c1 + dc1, c2 + dc2, n, m, grid);

                maxi = max(maxi, val);
            }
        }
        return maxi;
  }

//Memoization: TC:O(N*M*M); SC:O(N*M*M + N)
////dp[r][c1][c2] stores max no. of cherries collected by both when robot1 starts at (r,c1) and robot2 starts at (r,c2)
int rec(int r, int c1, int c2, int n, int m, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        if(c1 < 0 or c2 < 0 or c1 >= m or c2 >= m) return -1e8;

        if(r == n-1){ //Both robots have reached last row
            if(c1 == c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }

        if(dp[r][c1][c2] != 0) return dp[r][c1][c2];

        //explore all possible paths of both robots simultaneously
        int maxi=0;

        for(int dc1=-1; dc1<=1; dc1++){

            for(int dc2=-1; dc2<=1; dc2++){
            
                int val = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2]; //Determining if both robots are on the same cell or not
                val += rec(r+1, c1 + dc1, c2 + dc2, n, m, dp, grid);

                maxi = max(maxi, val);
            }
        }
        return dp[r][c1][c2] = maxi;
    }

//Tabulation: TC:O(N*M*M*9); SC:O(M*M*N)
int cherryPickup(vector<vector<int>>& grid) {
      int n=grid.size(), m=grid[0].size();
      vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

      //Set base cases
        for(int c1=0; c1<m; c1++){ 
            for(int c2=0; c2<m; c2++){
                dp[n-1][c1][c2] = (c1 == c2) ? grid[n-1][c1] : grid[n-1][c1] + grid[n-1][c2];
            }
        }
        
        for(int r=n-2; r>=0; r--)
        {
            for(int c1=0; c1<m; c1++)
            {
                for(int c2=0; c2<m; c2++)
                {
                    for(int dc1=-1; dc1<=1; dc1++)
                    {
                        for(int dc2=-1; dc2<=1; dc2++)
                        {
                            int val = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
                            if(c1+dc1 >=0 and c1+dc1 < m and c2+dc2 >= 0 and c2+dc2 < m) val += dp[r+1][c1 + dc1][c2 + dc2];

                            dp[r][c1][c2] = max(dp[r][c1][c2], val);
                        }
                    }
                }
            }
        }

        return dp[0][0][m-1];
    }
}
