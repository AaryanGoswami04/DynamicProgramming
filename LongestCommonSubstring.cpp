//https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//Tabulation: TC:O(M*N); SC:O(M*N)
//dp[i][j] stores the length of longest common LCS ending at index i of s1 and index j of s2  
int lcs(string &s1, string &s2){
    int n=s1.size();
    int m=s2.size();
    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

    //Set base cases
    for(int i=0; i<=m; i++) dp[0][i] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
              if (s1[i - 1] == s2[j - 1])
              {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, 1 + dp[i - 1][j - 1]);
              } 
            }
        }
       return ans;
}

//Space optimisation: SC:O(M)
int lcs(string &s1, string &s2){
    int n=s1.size();
    int m=s2.size();
    int ans=0;

    vector<int> prev(m+1, 0), curr(m+1, 0);
          
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }

            else curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}
