//https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Memoization: TC: O(N*4)*3; SC:O(N)+O(N*4)
int mem(int day, int last_task, vector<vector<int>>& dp,vector<vector<int>> &points){
    if(day == 0){
        int maxi=0;
        for(int task=0; task<3; task++){
            if(task != last_task)   maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    if(dp[day][last_task] != -1) return dp[day][last_task];

    int maxi=0;
    for(int task=0; task<3; task++){
      if (task != last_task) {
        int point = points[day][task] + mem(day - 1, task, dp, points);
        maxi = max(maxi, point);
      }
    }
  
    return dp[day][last_task]=maxi;
}

//Tabulation:TC: O(N*4)*3; SC:O(N*4)
int tab(int n, vector<vector<int>> &points){
   vector<vector<int>> dp(n, vector<int>(4,-1));
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][2], points[0][3]);
  dp[0][2] = max(points[0][1], points[0][0]);
  dp[0][3] = max(points[0][1], points[0][2], points[0][0]);

  for(int day=1; day<n; day++){
    for(int last_task=0; last_task<4; last_task++){
      for(int task=0; task<3; task++){
        if(task != last_task) dp[day][last_task] = max(dp[day][last_task], points[day][task] + dp[day-1][task]);
      }
    }
  }
  return dp[n-1][3];
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<vector<int>> dp(n, vector<int>(4,-1));
   return mem(n-1,3,dp, points);
}
