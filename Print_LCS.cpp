#include <iostream>
#include<vector>
using namespace std;

//dp[i][j] stores length of LCS in str1[i,m-1] to str2[j,n-1]
int main() {
   string s1="Atbcghi", s2="Bbctghi";
   int m=6, n=6;
  
   vector<vector<int>> dp(m+1, vector<int>(n+1,0));

  //Tabulation: TC:O(M*N); SC:O(M*N)
    for(int i=m-1; i>=0; i--){
      for(int j=n-1; j>=0; j--){
        if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i+1][j+1];
        
        else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
      }
    }

    string ans;
  
    int i=0,j=0;
    //TC:O(M+N); SC:O(1)
    while(i<m+1 and j<n+1){
      if(s1[i] == s2[j]){
        ans.push_back(s1[i]);
        i++;
        j++;
      }

      else if(dp[i+1][j] > dp[i][j+1]) i++;
        
      else j++;
    }
    cout<<ans<<endl;
}
