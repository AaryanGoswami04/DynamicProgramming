/*You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/

//https://leetcode.com/problems/target-sum/description/

/*Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000*/

/*Same as counting no. of subsets with sum =(total+target)/2;
        Every No. has + or - before it. Consider the expression 2-4+5-6-7;
        It  is the same as partioning the array [2,4,5,6,7] into 2 subsets {2,5}, {4,6,7} whose difference = target;
        S1+S2=Total; S1-S2=Target; This implies S1=(total+target)/2;
    */

//Memoization: TC:O(N*Target); SC:O(N*Target + N)
int rec(int idx, int n, vector<int>& arr,  vector<vector<int>>& dp, int target){
        if(idx == n-1){
            if(target == 0 and arr[n-1] == 0) return 2;
            if(target == 0 or target == arr[n-1]) return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];

        int notpick = rec(idx+1, n, arr, dp, target);
        int pick = (arr[idx] <= target) ? rec(idx+1, n, arr, dp, target-arr[idx]): 0;

        return dp[idx][target] = notpick + pick;
}

int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        int total_sum = 0;
        for(auto i:nums) total_sum += i;

        if(abs(target) > total_sum or (total_sum + target) % 2) return 0;

        target = (total_sum + target)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return rec(0, n, nums, dp, target);
  }
