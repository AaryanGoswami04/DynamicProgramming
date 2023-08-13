/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.*/

/*Input: str1 = "abac", str2 = "cab"
Output: "cabac"*/

//Len(Shortest Common Supersequence) = m + n - len(LCS)
//Tabulation: TC:O(M*N + M+N); SC:O(M*N)
//dp[i][j] stores the len of LCS in str1[i:m-1] and str2:[j:n-1]
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        string res;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(str1[i] == str2[j]) dp[i][j] = 1 +  dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }

        int i=0, j=0;
        while(i < m and j < n)
        {
            if(str1[i] == str2[j]){
                res.push_back(str1[i]);
                i++;
                j++;
            }
            else if(dp[i+1][j] > dp[i][j+1]){
                res.push_back(str1[i]);
                i++;
            }
            else{
                res.push_back(str2[j]);
                j++;
            }
        }

        //Push remaining part of str1, str2 to res
        while(i<m) res.push_back(str1[i++]);
        while(j<n) res.push_back(str2[j++]);

        return res;
}
