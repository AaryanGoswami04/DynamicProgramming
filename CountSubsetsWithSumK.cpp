//https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//Memoization: TC:O(N*K); SC:O(N*K + N)
//dp[idx][k] stores no. of subsets from idx to n-1 whose sum == k
 int MOD=1e9+7;
int rec(int idx, int n, vector<int>& arr, vector<vector<int>>& dp, int k){
	if(k == 0) return 1;

	if(idx == n-1) return (arr[idx] == k) ? 1 : 0;
	
	if(dp[idx][k] != -1) return dp[idx][k];

	int notpick = rec(idx+1, n, arr, dp, k)% MOD;
	int pick = (arr[idx] <= k) ? rec(idx+1, n, arr, dp, k-arr[idx]) % MOD: 0;

	return dp[idx][k] = (notpick + pick) % MOD;
}

//Tabulation: TC:O(N*K); SC:O(N*K)
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1,0));

	for(int i=0; i<n; i++) dp[i][0]=1;

	if(arr[n-1] <= k) dp[n-1][arr[n-1]]=1;

	for(int i=n-2; i>=0; i--)
	{
		for(int sum=k; sum>=0; sum--)
		{
			int notpick = dp[i+1][sum] % MOD;
			int pick = (arr[i] <= sum) ? dp[i+1][sum-arr[i]] % MOD : 0;
			
			dp[i][sum] = (notpick + pick) % MOD;
		}
	}

	return dp[0][k];
}

//Space optimisation: TC:O(N*K); SC:O(K)
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int> CurrRow(k+1,0), NextRow(k+1,0);

	NextRow[0] = CurrRow[0] = 1;

	if(arr[n-1] <= k) NextRow[arr[n-1]]=1;

	for(int i=n-2; i>=0; i--)
	{
		for(int sum=k; sum>=0; sum--)
		{
			int notpick = NextRow[sum] % MOD;
			int pick = (arr[i] <= sum) ? NextRow[sum-arr[i]] % MOD : 0;
			
			CurrRow[sum] = (notpick + pick) % MOD;
		}
		NextRow=CurrRow;
	}

	return  NextRow[k];
}
