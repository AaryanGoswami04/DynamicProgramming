//Given an integer array nums, return the length of the longest strictly increasing subsequence

//Memoization: TC:O(N^2); SC:O(N^2 + N)
//To handle -1 index in dp vector, prev stores 1-based indexing
//dp[i][j] stores length of LIS in arr[i,n-1] whose previous element in LIS is arr[j-1]
int rec(int idx, int prev, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int notpick = rec(idx+1, prev, n, nums, dp);
        int pick = (prev == 0 or nums[prev-1] < nums[idx]) ? 1 + rec(idx+1, idx+1, n, nums, dp) : 0;
       
        return dp[idx][prev] = max(pick, notpick);
}

//Tabulation: TC:O(N^2); SC:O(N^2 + N)
//To handle -1 index in dp vector, prev stores 1-based indexing
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int prev = i; prev >= 0; prev--)
            {
                int notpick = dp[i+1][prev];
                int pick = (prev == 0 or nums[prev-1] < nums[i]) ? 1 + dp[i+1][i+1] : 0;
                dp[i][prev] = max(pick, notpick);
            }
        }
        return dp[0][0];
}

//Space optimisation: TC:O(N^2); SC:O(2N)
//To handle -1 index in dp vector, prev stores 1-based indexing
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> Curr(n+1, 0), Next(n+1, 0);

        for(int i = n-1; i >= 0; i--)
        {
            for(int prev = i; prev >= 0; prev--)
            {
                int notpick = Next[prev];
                int pick = (prev == 0 or nums[prev-1] < nums[i]) ? 1 + Next[i+1] : 0;
                Curr[prev] = max(pick, notpick);
            }
            Next = Curr;
        }
        return Next[0];
}

//Optimised tabulation: TC:O(N^2); SC:O(N)
//dp[i] stores length of LIS ending at index i
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n,1);

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]) dp[i] = max(dp[i], 1 + dp[prev]);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
}

//Binary Search: 
//TC:O(N log N); SC:O(N)
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len = 1;

        vector<int> temp(1,nums[0]);

        for(int i=1; i<n; i++)
        {
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
}
