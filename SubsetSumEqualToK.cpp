//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Memoization: TC:O(N*Target); SC:O(N*Target + N)
//dp[idx][target] stores if it there is a subset whose sum=target from idx to n-1
bool rec(int idx, int n, int target, vector<vector<int>>& dp, vector<int> &arr){
    if(target == 0) return true;

    if(idx == n-1) return arr[n-1] == target;

    if(dp[idx][target] != -1) return dp[idx][target];

    bool NotTake = rec(idx+1, n, target, dp, arr);
    bool Take = (target >= arr[idx]) ? rec(idx+1, n, target-arr[idx], dp, arr) : false;

    return dp[idx][target] = NotTake or Take;
}

//Tabulation: TC:O(N*Target); SC:O(N*Target)
//dp[idx][target] stores if it there is a subset whose sum=target from idx to n-1
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1,0));

    //Set base cases
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[n-1][arr[n-1]] = true;

    for(int i=n-2; i>=0; i--){
        for(int target=k; target>=1; target--){
            bool NotTake = dp[i+1][target];
            bool Take = (target >= arr[i]) ? dp[i+1][target-arr[i]] : false;

            dp[i][target] = NotTake or Take;
        }
    }
    return dp[0][k];
}
