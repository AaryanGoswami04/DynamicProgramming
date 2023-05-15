/*198. House Robber 
https://leetcode.com/problems/house-robber/description/
To find max sum of non adjacent elements in an array*/
class Solution {
public:
// dp[i] stores the max sum of non adjacent elements in the subarray from index 0 to index i
    int mem(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[0]; //nums[1] hasn't been picked, so pick nums[0] to maximie the sum
        if(idx == -1) return 0; //nums[1] has been picked(and nums[0] has been excluded) so return 0 as no element lies before index 0 

        if(dp[idx] != -1) return dp[idx];

        int incl = nums[idx] + mem(idx-2, nums, dp);
        int excl = mem(idx-1, nums, dp);

        dp[idx] = max(incl, excl);
        return dp[idx];
    }
  
 int tab(vector<int>& nums, vector<int>& dp, int n){
        dp[0] = nums[0];

        for(int i=1; i<=n-1; i++){    
            int incl = i>1 ? nums[i] + dp[i-2] : nums[i];
            int excl = dp[i-1];

            dp[i] = max(incl, excl);
        }
        return dp[n-1];
    }
  
int space_opt(vector<int>& nums, int n){
  int prev2=0, prev1=nums[0];

  for(int i=1; i<n; i++){
       int incl = i>1 ? prev2 + nums[i] : nums[i];
       int excl = prev1;

       int curr = max(incl, excl);
       prev2 = prev1;
       prev1 = curr;
  }
  return prev1;
}
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        return mem(n-1, nums, dp, n);
    }
};
