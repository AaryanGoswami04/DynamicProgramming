/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.*/

//Memoiation: TC:O(2*N); SC:O(2*N + N)
//buy->1 means that prices[idx] can be bought, else it means prices[idx] cannot be bought
/*dp[i][1] stores max profit achievable starting from i to n-1, if it can be
bought, dp[i][0] stores max profit achievable starting from i, if it can be sold*/
int rec(int idx, int buy, int n, vector<int>& prices,vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = 0;
        if(buy){ //Not holding any stock currently, so this prices[idx] can be bought
            int Buy = -prices[idx] + rec(idx+1, 0, n, prices, dp);
            int notbuy = rec(idx+1, 1, n, prices, dp);

            profit = max(Buy, notbuy);
        }
        else{ //Prices[idx] can be sold
            int sell = prices[idx] + rec(idx+1, 1, n, prices, dp);
            int notsell = rec(idx+1, 0, n, prices, dp);

            profit = max(sell, notsell);
        }

        return dp[idx][buy] = profit;
}

//Tabulation: TC:O(2*N); SC:O(2*N)
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)  dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                else dp[i][buy] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
            }
        }
        return dp[0][1];
}

//Space optimisation: TC:O(2*N); SC:O(1)
int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<int> Next(2, 0), Curr(2, 0);

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(buy)  Curr[buy] = max(-prices[i] + Next[0], Next[1]);
                else Curr[buy] = max(prices[i] + Next[1], Next[0]);
            }
            Next = Curr;
        }
        return Next[1];
}
