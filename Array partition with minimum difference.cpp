/*You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
Return the minimum possible absolute difference.*/
//https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0
//Tabulation: TC:O(N*Target + Target/2); SC:O(N*Target)
//dp[idx][target] stores if there exists a subset from idx to n-1 whose sum==total
int minSubsetSumDifference(vector<int> &arr, int n) {
	int total = 0,mini=1e9;

	for(auto i:arr) total += i;

	vector<vector<bool>> dp(n, vector<bool>(total+1,0));

    //Set base cases
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[n-1] <= total) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int target=1; target<=total; target++){
            bool NotTake = dp[i-1][target];
            bool Take = (target >= arr[i]) ? dp[i-1][target-arr[i]] : false;

            dp[i][target] = NotTake | Take;
        }
    }
	
	for(int sum1=0; sum1<=total/2; sum1++)
	{
		if(dp[n-1][sum1] == 1)
		{
			int sum2 = total-sum1;
			mini = min(mini, abs(sum1-sum2));
		}
	}

	return mini;
}

//Space optimisation:
int minSubsetSumDifference(vector<int> &arr, int n) {
	int total = 0,mini=1e9;

	for(auto i:arr) total += i;

	vector<bool> CurrRow(total+1,0), NextRow(total+1,0);

    //Set base cases
    NextRow[0] = true;
    NextRow[arr[n-1]] = true;

    for(int i=n-2; i>=0; i--){
        
        CurrRow[0] = true;
        for(int target=total; target>=1; target--){
            bool NotTake = NextRow[target];
            bool Take = (target >= arr[i]) ? NextRow[target-arr[i]] : false;

            CurrRow[target] = NotTake or Take;
        }
        NextRow = CurrRow;
    }
    
	for(int sum1=0; sum1<=total/2; sum1++)
	{
		if(CurrRow[sum1] == 1)
		{
			int sum2 = total-sum1;
			mini = min(mini, abs(sum1-sum2));
		}
	}

	return mini;
}
