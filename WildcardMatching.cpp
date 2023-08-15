/*Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).*/

/*Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.*/

//Memoization: TC:O(MN); SC:O(MN + Stack space)
//dp[i][j] stores if s[0,i] matches with p[0,j]
bool rec(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i<0 and j<0) return true; //Boths string are null

        if(i >= 0 and j < 0) return false; // The pattern string has become empty, hence it can't be matched with a non empty string s

        if (i < 0 and j >= 0) //Pattern string is remaining and s is empty, it can onlybe matched if remaning pattern string contains only '*'
        {
            for (int k = 0; k <= j; k++){
                if (p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '?' or p[j] == s[i]) return dp[i][j]= rec(i-1, j-1, s, p, dp);

        else if(p[j] == '*') return dp[i][j] = rec(i-1, j, s, p, dp) or rec(i, j-1, s, p, dp);

        return dp[i][j] = false; //s[i] and p[j] are 2 lowercase characters and don't match
}

//Tabulation: TC:O(MN); SC:O(MN)
//dp[i][j] stores if s[0,i-1] matches with p[0,j-1]
bool isMatch(string s, string p) {
       int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        //Set base cases
        dp[0][0] = 1;
        //Optional since, dp is already initialized as false
        for(int j=1; j<=n; j++) dp[0][j] = false;

        for(int j = 1; j <= n; j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[j-1] == '?' or p[j-1] == s[i-1]) dp[i][j] = dp[i-1][j-1];

                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];

                else dp[i][j] = false;
            }
        }
        return dp[m][n];
}

//Space optimisation: TC:O(MN); SC:O(2N)
bool isMatch(string s, string p) {
       int m = s.size(), n = p.size();
        vector<bool> CurrRow(n+1, 0), PrevRow(n+1, 0);

        //Set base cases
        PrevRow[0] = 1;
    
        for(int j = 1; j <= n; j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            PrevRow[j] = flag;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[j-1] == '?' or p[j-1] == s[i-1]) CurrRow[j] = PrevRow[j-1];

                else if(p[j-1] == '*') CurrRow[j] = PrevRow[j] or CurrRow[j-1];

                else CurrRow[j] = false;
            }
            PrevRow = CurrRow;
        }
        return PrevRow[n];
}
