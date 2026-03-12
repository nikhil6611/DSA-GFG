class Solution {
  public:
    int helper(int day, int last,int n,vector<vector<int>>& mat,vector<vector<int>>&dp){
        if(day==n-1){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i==last)continue;
                maxi=max(maxi,mat[day][i]);
            }
            return maxi;
        }
        if(dp[day][last]!=-1){
            return dp[day][last];
        }
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i==last)continue;
            int points=mat[day][i]+helper(day+1,i,n,mat,dp);
            maxi=max(maxi,points);
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
       
        vector<vector<int>>dp(mat.size(),vector<int>(4,-1));
        return  helper(0,3,mat.size(),mat,dp);
    }
};