/*Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character*/

//Memoization: TC:O(M*N); SC:O(M*N + M+N)
//dp[i][j] sotres the min no. of operations req to convert s1[i,n-1] to s2[j,m-1]
int rec(int i, int j, int n, int m, string& s1, string& s2,vector<vector<int>>& dp){
        if(j >= m) return n-i; //s2 has become an empty string. Min no. of operations to convert s1[i,n-1] to "" = size(s1) = n-i;
        if(i >= n) return m-j;//s1 has become an empty string. Min no. of operations to convert "" to s2[j,m-1] = size(s2) = m-j;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = rec(i+1, j+1, n, m, s1, s2, dp);
        else{
            int del = rec(i+1, j, n, m, s1, s2, dp);
            int replace = rec(i+1, j+1, n, m, s1, s2, dp);
            int insert = rec(i, j+1, n, m, s1, s2, dp);

            return dp[i][j] = min(del, min(replace, insert)) + 1;
        }
}

//Tabulation: TC:O(M*N); SC:O(M*N)
int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        //Set base cases
        for(int i=0; i<=n; i++) dp[i][m] = n-i;
        for(int j=0; j<=m; j++) dp[n][j] = m-j;


        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else{
                    int del = dp[i+1][j];
                    int replace = dp[i+1][j+1];
                    int insert = dp[i][j+1];

                    dp[i][j] = min(del, min(replace, insert)) + 1;
                }
            }
        }
      return dp[0][0];
}

//Space optimisation: TC:O(M*N); SC:O(M)
int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> CurrRow(m+1,0), NextRow(m+1, 0);

        //Set base cases
        for(int j=0; j<=m; j++) NextRow[j] = m-j;


        for(int i=n-1; i>=0; i--)
        {
            CurrRow[m] = n - i; 
            for(int j=m-1; j>=0; j--)
            {
                if(word1[i] == word2[j]) CurrRow[j] = NextRow[j+1];
                else{
                    int del = NextRow[j];
                    int replace = NextRow[j+1];
                    int insert = CurrRow[j+1];

                    CurrRow[j] = min(del, min(replace, insert)) + 1;
                }
            }
            NextRow = CurrRow;
        }
        return NextRow[0];
 }
