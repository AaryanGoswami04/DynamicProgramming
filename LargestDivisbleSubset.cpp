/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.*/

//Longest subseq such every pair is divisble
//TC:O(N^2); SC:O(N)
vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), maxLen = 0, maxIdx = 0;
        vector<int> dp(n,1), hash(n), temp;

        for(int i = 1; i < n; i++)
        {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++)
            {
                if(nums[i] % nums[prev] == 0 and dp[i] < dp[prev]+1)
                {
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
            }

            if(maxLen < dp[i]){
                maxIdx = i;
                maxLen = dp[i];
            }
        }

        temp.push_back(nums[maxIdx]);
        while(hash[maxIdx] != maxIdx)
        {
            maxIdx = hash[maxIdx];
            temp.push_back(nums[maxIdx]);
        }
        //Since the subseq can be in any order, temp is not reversed
        return temp;
}
