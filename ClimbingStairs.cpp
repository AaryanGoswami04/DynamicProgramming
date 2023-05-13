//You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//Similar to fibonacci series
int mem(vector<int>& dp, int n){
        if(n==0 or n==1) return 1;
        if(dp[n] != -1) return dp[n];
        return mem(dp, n-1) + mem(dp, n-2);
}
int tab(vector<int>& dp, int n){
        dp[0]=1, dp[1]=1;
        for(int i=2; i<=n; i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
 }
 int space_opt(int n){  //SC: O(1)
        int prev=1, prev2=0;

        for(int i=2; i<=n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
 int climbStairs(int n) {
        vector<int> dp(n+1, -1); //dp[n] stores no. of ways to reach nth stair from 0th stair
        return tab(dp, n);
 }
