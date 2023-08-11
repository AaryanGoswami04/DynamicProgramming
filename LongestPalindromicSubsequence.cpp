/*Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.*/

//Same as finding the LCS of s and reversed s
//dp[i][j] stores length of LCS in s1[i,n-1] to s2[j,n-1]
//Memoization: TC:O(N^2 + N); SC:O(N^2 + N + Stack space)
int rec(int i, int j, string& s1, string& s2, vector<vector<int>>& dp, int n){
      if(i == n or j == n) return 0;

      if(dp[i][j] != -1) return dp[i][j];
        
      if(s1[i] == s2[j]) return dp[i][j] = 1 + rec(i+1, j+1, s1, s2, dp, n);

      return dp[i][j] = max(rec(i, j+1, s1, s2, dp, n), rec(i+1, j, s1, s2, dp, n));
}
string rev(string& s, int n){
      string ans = "";
      for(int i=n-1; i>=0; i--) ans.push_back(s[i]);
        
      return ans;
  }

//Tabulation: TC:O(N^2 + N); SC:O(N^2 + N)
int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        string rev_s = rev(s, n);
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(s[i] == rev_s[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
  }

//Space optimisation: TC:O(N^2 + N); SC:O(2N)
int longestPalindromeSubseq(string s) {
        int n=s.size();
        string rev_s = rev(s, n);
        
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == rev_s[j-1]) curr[j] = 1 + prev[j-1];

                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
  }
