/*Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.*/

//Memoization: TC:O(M*N); SC:O(M*N + M+N)
//dp[i][j] stores length of LCS in two strings: s1[0,i-1] and s2[0,j-1];
int rec(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& dp){
        if(idx1 == 0 or idx2 == 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s1[idx1-1] == s2[idx2-1])  return dp[idx1][idx2] = 1 + rec(idx1-1, idx2-1, s1, s2, dp);

        return dp[idx1][idx2] = max(rec(idx1-1, idx2, s1, s2, dp), rec(idx1, idx2-1, s1, s2, dp));
}

//Tabulation: TC:O(M*N); SC:O(M*N)
//dp[i][j] stores length of LCS in two strings: s1[0,i-1] and s2[0,j-1];
int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        //Set base cases
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 +dp[i-1][j-1];

                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
 }

 //Space optimisation: TC:O(M*N); SC:O(M)
  int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int i=0; i<=m; i++) prev[i] = 0;
      
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];

                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
  }
