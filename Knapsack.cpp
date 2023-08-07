/*Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible. 

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all [It is not possible to put a part of an item into the bag].*/
//Memoization: TC:O(N*MaxWt); SC:O(N*MaxWt + N)
//dp[i][Wt] stores max possible value which can be achieved from idx 0 to i, provided the weight of bag=Wt
int rec(int idx,  int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
    if (idx == 0) {
		  return (wt[0] <= W) ? val[0] : 0;
    }

    if(dp[idx][W] != -1) return dp[idx][W];
	
	  int notpick = rec(idx-1, W, wt, val, dp);
	  int pick = (wt[idx] <= W) ? (val[idx] + rec(idx-1, W-wt[idx], wt, val, dp)) : INT_MIN;

	  return dp[idx][W] = max(notpick, pick);
}

//Tabulation: TC:O(N*MaxWt); SC:O(N*MaxWt)
//dp[i][Wt] stores max possible value which can be achieved from idx 0 to i, provided the weight of bag=Wt
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
  
  	for(int wt = weight[0]; wt <= maxWeight; wt++) dp[0][wt] = value[0];
  
  	for(int i=1; i<n; i++)
  	{
  		for(int w = 0; w <= maxWeight; w++)
  		{
  				int notpick = dp[i-1][w];
  				int pick = (weight[i] <= w) ? (value[i] + dp[i-1][w-weight[i]]) : 0;
  
  				dp[i][w] = max(notpick, pick);
  		}
  	}
  
  	return dp[n-1][maxWeight];
}

//Space optimisation: TC:O(N*MaxWt); SC:O(2*MaxWt)

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  	vector<int> CurrRow(maxWeight+1 , 0), PrevRow(maxWeight+1, 0);
  
  	for(int wt = weight[0]; wt <= maxWeight; wt++) PrevRow[wt] = value[0];
  
  	for(int i=1; i<n; i++)
  	{
  		for(int w = 0; w <= maxWeight; w++)
  		{
  			int notpick = PrevRow[w];
  			int pick = (weight[i] <= w) ? (value[i] + PrevRow[w-weight[i]]) : 0;
  
  			CurrRow[w] = max(notpick, pick);
  		}
  		PrevRow = CurrRow;
  	}
  
  	return PrevRow[maxWeight];
}

//Space optimisation: TC:O(N*MaxWt); SC:O(MaxWt) (ONLY SINGLE ROW USED) 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> PrevRow(maxWeight+1, 0);

	for(int wt = weight[0]; wt <= maxWeight; wt++) PrevRow[wt] = value[0];

	for(int i=1; i<n; i++)
	{
		for(int w = maxWeight; w >= 0; w--)
		{
			int notpick = PrevRow[w];
			int pick = (weight[i] <= w) ? (value[i] + PrevRow[w-weight[i]]) : 0;

			PrevRow[w] = max(notpick, pick);
		}
	}

	return PrevRow[maxWeight];
}
