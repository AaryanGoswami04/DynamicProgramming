/*You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.*/

//Memoiation: TC:O(2*N); SC:O(2*N + N)
//Similiar to 122
int rec(int idx, int buy, int n, int fee, vector<int>& prices,vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = 0;
        if(buy){ //Not holding any stock currently, so this prices[idx] can be bought
            int Buy = -prices[idx] + rec(idx+1, 0, n, fee, prices, dp);
            int notbuy = rec(idx+1, 1, n, fee, prices, dp);

            profit = max(Buy, notbuy);
        }
        else{ //Prices[idx] can be sold
            int sell = prices[idx] + rec(idx+1, 1, n, fee, prices, dp) - fee;
            int notsell = rec(idx+1, 0, n, fee, prices, dp);

            profit = max(sell, notsell);
        }
        return dp[idx][buy] = profit;
}

//Tabulation: TC:O(N); SC:O(N*2)
int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int i=n-1; i>=0; i--)
        {
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+1][1] - fee, dp[i+1][0]);
        }
        return dp[0][1];
}

//Space optimisation: TC:O(N); SC:O(1)
int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
       vector<int> Next(2, 0), Curr(2, 0);

        for(int i=n-1; i>=0; i--)
        {
            Curr[1] = max(-prices[i] + Next[0], Next[1]);
            Curr[0] = max(prices[i] + Next[1] - fee, Next[0]);

            Next = Curr;
        }
        return Next[1];
}
