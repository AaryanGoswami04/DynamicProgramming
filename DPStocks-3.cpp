/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).*/

//Memozation: TC:O(N*2*3); SC:O(N*2*3 + N)
//dp[idx][1][cap] stores the max profit acheivable from arr[i,n-1], provided prices[i] can be bought(if cap>0)
//cap stores the no. of transaction currently left
int rec(int idx, int buy, int cap, int n, vector<int>& prices,  vector<vector<vector<int>>>& dp){ 
        if(idx == n or cap == 0) return 0;

        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int profit = 0;
        if(buy){
            int Buy = -prices[idx] + rec(idx+1, 0, cap, n, prices, dp);
            int notbuy = rec(idx+1, 1, cap, n, prices, dp);

            profit = max(Buy, notbuy);
        }

        else{
            int sell = prices[idx] + rec(idx+1, 1, cap-1, n, prices, dp);
            int notsell = rec(idx+1, 0, cap, n, prices, dp);

            profit = max(sell, notsell);
        }
        return dp[idx][buy][cap] = profit;
}

 //Tabulation: TC:O(N*2*2); SC:O(N*2*3)
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        for(int i = n-1; i >= 0; i--)
        {
            for(int cap = 2; cap >= 1; cap--) //for cap=0, every dp entry =0, so it's not computed in for loop
            {
                for(int buy = 1; buy >= 0; buy--)
                {
                    if(buy)  dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    else dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
}

//Space optimisation: TC:O(N*2*3); SC:O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> Curr(2, vector<int>(3,0)), Next(2, vector<int>(3,0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int cap = 2; cap >= 1; cap--) //for cap=0, every dp entry =0, so it's not computed in for loop
            {
                for(int buy = 1; buy >= 0; buy--)
                {
                    if(buy)  Curr[buy][cap] = max(-prices[i] + Next[0][cap], Next[1][cap]);
                    else Curr[buy][cap] = max(prices[i] + Next[1][cap-1], Next[0][cap]);
                }
            }
            Next = Curr;
        }
        return Next[1][2];
}
