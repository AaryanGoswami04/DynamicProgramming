//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
#include <bits/stdc++.h> 
int rec(int n, vector<int> &heights){ //Recursion: TLE
    if(n==0) return 0;
    
    int left=INT_MAX, right=INT_MAX;
    
    left = rec(n-1, heights)+abs(heights[n]-heights[n-1]);
    if(n>1) right = rec(n-2, heights)+abs(heights[n]-heights[n-2]); //For 1st stair, n-2 will be -1, which DNE
    
    return min(left,right);
}

int mem(int n, vector<int> &heights, vector<int>& dp){  //TC: O(N); SC:O(2N)
    if(n==0) return 0;
    
    if(dp[n] != -1) return dp[n];

    int left=INT_MAX, right=INT_MAX;
    left = mem(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    if(n>1) right = mem(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    
    dp[n]=min(left, right);
    return dp[n];
}

int tab(int n, vector<int> &heights){ //SC:O(N)
  vector<int> dp(n);  
  dp[0]=0;
  
    for(int i=1; i<=n-1; i++){
        int step1 = dp[i-1] + abs(heights[i]-heights[i-1]);
        int step2 = INT_MAX;
        if(i>1) step2 = dp[i-2] + abs(heights[i]-heights[i-2]);

        dp[i] = min(step1, step2);
    }
    return dp[n-1];
}

int space_opt(int n, vector<int> &heights){ //SC: O(1)
    int prev1=0, prev2=0;

    for(int i=1; i<=n-1; i++){
       int step1 = prev1 + abs(heights[i]-heights[i-1]);
       int step2 = INT_MAX;
       if(i>1) step2 = prev2 + abs(heights[i]-heights[i-2]);

       int curr = min(step1, step2);
       prev2 = prev1;
       prev1 = curr;
    }
    return prev1;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return tab(n, heights);
}
