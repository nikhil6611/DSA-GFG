class Solution {
  public:
  int solvemem(vector<int>&coins,int n,int sum,vector<vector<int>>&dp){
      if(sum==0) return 1;
      if(sum<0) return 0;
      if(n==0) return 0;
      if(dp[n][sum]!=-1) return dp[n][sum];
      int exclude = solvemem(coins,n-1,sum,dp);
      int include = solvemem(coins,n,sum-coins[n-1],dp);
      return dp[n][sum]=exclude+include;
  }
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       return solvemem(coins,coins.size(),sum,dp);
    }
};