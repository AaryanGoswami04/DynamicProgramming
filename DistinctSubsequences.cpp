//Given two strings s and t, return the number of distinct subsequences of s which equals t.

//Memoization: TC:O(M*N); SC:O(M*N + M+N)
//dp[i][j] stores no. of distinct subseq of t[j,n-1] in s[i,m-1]
int rec(int i, int j, int m, int n, string& s, string& t, vector<vector<int>>& dp){
        if(j >= n) return 1;
        if(i >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = rec(i+1, j+1, m, n, s, t, dp) + rec(i+1, j, m, n, s, t, dp);
        else return dp[i][j] = rec(i+1, j, m, n, s, t, dp);
}

//Tabulation: TC:O(M*N); SC:O(M*N)
int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
         
        vector<vector<double>> dp(m+1, vector<double>(n+1,0)); //To avoid TLE, data type is double

        //Set base cases
        for(int i=0; i<=m; i++) dp[i][n] = 1;

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(s[i] == t[j]) dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                else dp[i][j] = dp[i+1][j];
            }
        }
        return (int)dp[0][0];
}

//Space optimisation: TC:O(M*N); SC:O(2N)
int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
         
        vector<double> CurrRow(n+1,0), NextRow(n+1,0); //To avoid TLE, data type is double

        NextRow[n] = CurrRow[n] = 1;

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(s[i] == t[j]) CurrRow[j] = NextRow[j+1] + NextRow[j];
                else CurrRow[j] = NextRow[j];
            }
            NextRow = CurrRow;
        }
        return (int)NextRow[0];
}
