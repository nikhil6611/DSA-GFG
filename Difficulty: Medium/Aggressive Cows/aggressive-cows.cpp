class Solution {
  public:
    bool isvalid(int mid, vector<int> &stalls, int k){
        int cowcount=1, nearestcow=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-nearestcow>=mid){
                cowcount++;
                nearestcow= stalls[i];
            }
        }
        if(cowcount>=k){
            return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int ans;
        sort(stalls.begin(),stalls.end());
     int start=1, end= stalls.back()-stalls.front();
     while(start<=end){
         int mid= start+(end-start)/2;
         if(isvalid(mid, stalls,k)){
             ans= mid;
             start= mid+1;
         }
         else{
             end=mid-1;
         }
     }
     return ans;
        
    }
};