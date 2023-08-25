//https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
/*You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.*/

/*Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].*/

//TC:O(N^2); SC:O(2N)
//Req ans = nums.size() - len(Longest Mountain subsequence)
int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = 0; //len(Longest Mountain subsequence)
        vector<int> dp1(n,1), dp2(n,1); //dp1[i] stores len(LIS) ending at i in nums[0,i];  dp2[i] stores len(LIS) ending at i in nums[n-1,i]

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]) dp1[i] = max(dp1[i], 1 + dp1[prev]);
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int next = n-1; next > i; next--){
                if(nums[next] < nums[i]) dp2[i] = max(dp2[i], 1 + dp2[next]);
            }
        }

        for(int i=0; i<n; i++){
            if(dp1[i] > 1 and dp2[i] > 1) ans = max(ans, dp2[i]+dp1[i]-1);
        }

        return n-ans;
}
