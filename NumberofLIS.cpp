//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.

//TC:O(N^2); SC:O(N)
int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen=1;
        vector<int> dp(n,1); //dp[i] stores len(longest LIS) ending at index i
        vector<int> cnt(n,1);  // cnt[i] stores no. of longest LIS ending at index i

        for(int i=0; i<n; i++)
        {
            for(int prev=0; prev<i; prev++)
            {
                if(nums[prev] < nums[i] and 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(nums[prev] < nums[i] and 1 + dp[prev] == dp[i]) cnt[i] += cnt[prev];
                maxLen = max(maxLen, dp[i]);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxLen) ans += cnt[i];
        }
      
        return ans;
}
