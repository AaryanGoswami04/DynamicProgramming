/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.(Top floor is the nth index i.e the index after the last index of vector)*/

//Tabulation method: 
//TC: O(N)
//SC: O(N)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++)
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        return min(dp[n-2], dp[n-1]);
    }
};
