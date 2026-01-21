class Solution {
public:
    bool valid(int mid, int n, int k, vector<int>& nums){
        int subarray=1, sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                return false;
            }
                    if(sum+nums[i]<=mid){
                        sum+=nums[i];
                    }
                    else{
                        subarray++;
                        sum= nums[i];
                    }
        }
        if(subarray<=k){
            return true;
        }
        return false;
    }
    int findPages(vector<int>& nums, int k) {
        if(k>nums.size()){
            return -1;
        }
        int totalsum=0;
        int ans;
        for(int i=0;i<nums.size();i++){
                    totalsum+=nums[i];
        }
        int start=*max_element(nums.begin(), nums.end()), end= totalsum;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(valid(mid,nums.size(),k,nums)){
                ans= mid;
                end= mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};