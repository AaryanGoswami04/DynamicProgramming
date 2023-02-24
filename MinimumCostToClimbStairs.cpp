/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.(Top floor is the nth index i.e the index after the last index of vector)*/
//Recursion
//TC: Exponential
//SC: O(N)
int rec(vector<int>& cost, int top){
        if(top == 0)
            return cost[0];
        else if(top == 1)
            return cost[1];

         int ans = cost[top] + min(rec(cost, top-1, dp), rec(cost,top-2,dp));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(rec(cost, n-1),rec(cost, n-2)); //To reach the top floor, the cost of top floor itself needs to be excluded
        return ans;
    }
};
//Recursion + Memoization
//TC: O(2N)
//SC: O(N)
    int rec(vector<int>& cost, int top, vector<int>& dp){
        if(top == 0)
            return cost[0];
        else if(top == 1)
            return cost[1];

        if(dp[top] != -1)
            return dp[top];

        dp[top] = cost[top] + min(rec(cost, top-1, dp), rec(cost,top-2,dp));
        return dp[top];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        int ans = min(rec(cost, n-1, dp),rec(cost, n-2, dp)); //To reach the top floor, the cost of top floor itself needs to be excluded
        return ans;
    }
};
//Tabulation method: 
//TC: O(N)
//SC: O(N)
//dp[k] is stores the minimum cost to reach kth stair from 0th or 1st stair
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
//Most Optimised:
//TC: O(N)
//SC: O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr_cost = 0;

        for(int i=2; i<n; i++){
            curr_cost = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr_cost;
        }
        return min(prev2, prev1);
    }
};
