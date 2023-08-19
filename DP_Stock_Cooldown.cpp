/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/

//Memoiation: TC:O(2*N); SC:O(2*N + N)
int rec(int idx, int buy, int n, vector<int>& prices,vector<vector<int>>& dp){
        if(idx >= n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = 0;
        if(buy){ //Not holding any stock currently, so this prices[idx] can be bought
            int Buy = -prices[idx] + rec(idx+1, 0, n, prices, dp);
            int notbuy = rec(idx+1, 1, n, prices, dp);

            profit = max(Buy, notbuy);
        }
        else{ //Prices[idx] can be sold
            int sell = prices[idx] + rec(idx+2, 1, n, prices, dp);
            int notsell = rec(idx+1, 0, n, prices, dp);

            profit = max(profit, max(sell, notsell));
        }

        return dp[idx][buy] = profit;
}

//Tabulation: TC:O(N); SC:O(2*N)
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for(int i=n-1; i>=0; i--)
        {
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
        }
        
        return dp[0][1];
}
