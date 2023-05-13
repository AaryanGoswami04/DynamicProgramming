class Solution {
public:
    int mem(vector<int>& dp, int n){  //TC: O(N); SC: O(2N)
        if(n<=1) return n; //base case
        if(dp[n] != -1) return dp[n]; //if subproblem is already computed return its value
        return mem(dp, n-1) + mem(dp, n-2); //else compute smaller subproblems
    }
  
   int tab(vector<int>& dp, int n){ //SC: O(N)
        dp[0]=0, dp[1]=1;
     
        for(int i=2; i<=n; i++)
            dp[i] = dp[i-1]+dp[i-2];
     
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
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return mem(dp, n);
    }
};
