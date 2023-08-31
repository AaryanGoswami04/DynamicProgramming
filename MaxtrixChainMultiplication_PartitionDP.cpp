//Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

//Memoization: TC:O(N^3); SC:O(N)
//dp[i][j] stores the min operartions to multiply ith matrix to jth matrix
int rec(int i, int j, vector<int> &arr, vector<vector<int>>& dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini=1e9;
    for(int k=i; k<=j-1; k++){
        int steps = arr[i-1] * arr[k] * arr[j] + rec(i,k,arr,dp) + rec(k+1,j,arr,dp);
        mini = min(steps, mini);
    }

    return dp[i][j] = mini;
}
