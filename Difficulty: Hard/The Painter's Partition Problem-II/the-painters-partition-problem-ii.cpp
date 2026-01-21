class Solution {
  public:
  bool isvalid(int mid, vector<int>& arr,int n, int k){
      int painter=1, time=0;
      for(int i=0;i<n;i++){
          if(arr[i]+time <=mid){
              time+= arr[i];
          }else{
              painter++;
              time=arr[i];
          }
      }
      if(painter<=k){
          return true;
      }
      return false;
  }
    int minTime(vector<int>& arr, int k) {
        int mintime;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int start=*max_element(arr.begin(),arr.end()), end= sum;
        while(start<=end){
            int mid= start+ (end-start)/2;
            if(isvalid(mid,arr,arr.size(),k)){
                mintime=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return mintime;
    }
};