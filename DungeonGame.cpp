/*The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Return the knight's minimum initial health so that he can rescue the princess.
Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.*/

//Memoization: TC:O(M*N); SC:O(M*N + M+N)
//dp[i][j] stores MinHealth req to reach (m-1, n-1) from (i,j)
int rec(int r, int c, int m, int n, vector<vector<int>>& dp, vector<vector<int>> &grid){
        
        //Destination reached
        if(r == m-1 and c == n-1) return (grid[r][c] <= 0) ? -grid[r][c] + 1 : 1;

        if(dp[r][c] != 1e7) return dp[r][c];

        int Right=1e9, Down=1e9;
        if(c+1 < n) Right = rec(r, c+1, m, n, dp, grid);
        if(r+1 < m) Down = rec(r+1, c, m, n, dp, grid);
       
        int minHealth = min(Right, Down) - grid[r][c];

        return dp[r][c] = (minHealth <= 0) ? 1 : minHealth;
}

//Tabulation: TC:O(M*N); SC:O(M*N)
//dp[i][j] stores MinHealth req to reach (m-1, n-1) from (i,j)
int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n,1e7));

        dp[m-1][n-1] = (dungeon[m-1][n-1] <= 0) ? -dungeon[m-1][n-1] + 1 : 1;

        for(int r=m-1; r>=0; r--)
        {
            for(int c=n-1; c>=0; c--)
            {
                if(r == m-1 and c == n-1) continue;

                int Right=1e9, Down=1e9;
                if(c+1 < n) Right = dp[r][c+1];
                if(r+1 < m) Down = dp[r+1][c];
       
                int minHealth = min(Right, Down) - dungeon[r][c];
                dp[r][c] = (minHealth <= 0) ? 1 : minHealth;
            }
        }

        return dp[0][0];
}


    

