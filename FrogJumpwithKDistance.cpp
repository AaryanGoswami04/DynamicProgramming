//Similar to Frog jump problem except the froh can jump fron ith step to i+1, i+2, i+3....(i+k)th step
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int rec(int n, vector<int> &heights, int k) { // Recursion: TLE
  if (n == 0)  return 0;
  
  int ans = INT_MAX;
  for (int i = 1; i <= k; i++) {
    int candidate;
    if (n - i >= 0)   candidate = rec(n - i, heights, k) + abs(heights[n] - heights[n - i]);
    ans = min(ans, candidate);
  }
  return ans;
}

int mem(int n, vector<int> &heights, vector<int>& dp, int k) {  //TC: O(N*K) SC:O(N)
  if (n == 0)
    return 0;

  if(dp[n] != -1) return dp[n];
  
  int ans = INT_MAX;
  for (int i = 1; i <= k; i++) {
    int candidate;
    if (n - i >= 0)  candidate = rec(n - i, heights, k) + abs(heights[n] - heights[n - i]);
    dp[n] = min(dp[n], candidate);
  }
  return dp[n-1];
}

int tab(int n, vector<int> &heights, int k){  //TC: O(N*K) SC:O(N)
  vector<int> dp(n, INT_MAX);
  dp[0]=0;

  for(int i=1; i<n; i++){
     int candidate=0;
     for(int j=1; j<=k; j++){
       if(i-j >= 0) candidate = dp[i-j] + abs(heights[i] - heights[i-j]);
       dp[i]=min(dp[i], candidate);
     }
  }
  return dp[n-1];
}

int main() {
  vector<int> heights{10, 30, 30, 50};
  int n = 3;
  int k = 3;
  cout << rec(n, heights, k);
}
