/*you are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.*/

/*Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1*/

//dp[i][amt] stores no. of ways it is possible to sum up to amt from idx i to n-1
//Memoization: TC:O(N*Amount); SC:O(N*Amount + Auxiliary stack space)
int rec(int idx, int n, int amt, vector<vector<int>>& dp, vector<int>& coins){
        if(idx == n-1) return amt % coins[idx] == 0;

        if(dp[idx][amt] != -1) return dp[idx][amt];

        int notpick = rec(idx+1, n, amt, dp, coins);
        int pick = (coins[idx] <= amt) ? rec(idx, n, amt-coins[idx], dp, coins) : 0;

        return dp[idx][amt] = notpick + pick;
}

//Tabulation: TC:O(N*Amount); SC:O(N*Amount)

int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        //set base cases
        for(int amt=0; amt <= amount; amt++)
            dp[n-1][amt] = amt % coins[n-1] == 0; 

        for(int i=n-2; i>=0; i--)
        {
            for(int amt=0; amt <= amount; amt++)
            {
                int notpick = dp[i+1][amt];
                int pick = (coins[i] <= amt) ? dp[i][amt-coins[i]] : 0;

                dp[i][amt] = notpick + pick;
            }
        }
        return dp[0][amount];
}

//Space optimisation: TC:O(N*Amount); SC:O(2*Amount)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
       vector<int> CurrRow(amount+1, 0), NextRow(amount+1, 0);

        //set base cases
        for(int amt=0; amt <= amount; amt++)  NextRow[amt] = amt % coins[n-1] == 0; 

        for(int i=n-2; i>=0; i--)
        {
            for(int amt=0; amt <= amount; amt++)
            {
                int notpick = NextRow[amt];
                int pick = (coins[i] <= amt) ? CurrRow[amt-coins[i]] : 0;

                CurrRow[amt] = notpick + pick;
            }
            NextRow = CurrRow;
        }
        return NextRow[amount];
    }
