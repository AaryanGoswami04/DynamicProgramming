//TC:O(N^2); SC:O(2N)
void PrintLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1, maxIdx = 0;
        vector<int> dp(n,1), hash(n), res;

        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++)
            {
                if(nums[prev] < nums[i] and 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }   
            if(maxLen < dp[i]){
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        res.push_back(nums[maxIdx]);
        while(hash[maxIdx] != maxIdx)
        {
            maxIdx = hash[maxIdx];
            res.push_back(nums[maxIdx]);
        }
        
        reverse(res.begin(), res.end());

        for(auto i:res) cout<<i<<" ";
}
