/*here is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.*/
//dp[i][j] stores no. of unique paths from (0,0) to (i,j)
int mem(int r, int c, int m, int n, vector<vector<int>>& dp){ //TC:O(M*N); SC:O(M*N)
        if(r == 0 and c == 0) return 1;

        if(r<0 or c<0) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int up = mem(r-1, c, m, n, dp);
        int left = mem(r, c-1, m, n, dp);

        return dp[r][c] = up+left;
}

int Tabulation(int m, int n) { //TC:O(M*N); SC:O(M*N)

        vector<vector<int>> dp(m, vector<int> (n,0));

        dp[0][0] = 1;

        for(int r=0; r<m; r++){

            for(int c=0; c<n; c++){
                int up=0, left=0;

                if(r==0 and c==0) continue;
                
                if(r>0) up = dp[r-1][c];
                if(c>0) left = dp[r][c-1];

                dp[r][c] = up+left;   
            }
        }
        return dp[m-1][n-1];
}

int SpaceOpt(int m, int n) { //TC:O(M*N); SC:O(N)
        vector<int> prev(n, 0);
        
        for(int r=0; r<m; r++){

            vector<int> curr(n,0);

            for(int c=0; c<n; c++){
                int up=0, left=0;

                if(r==0 and c==0) curr[c] = 1;

                else{ 
                    if(r>0) up = prev[c];
                    if(c>0) left = curr[c-1];

                    curr[c] = up+left;   
                }
            }
            prev = curr;
        }
        return prev[n-1];
}

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));

        return mem(m-1, n-1, m, n, dp);
    }
