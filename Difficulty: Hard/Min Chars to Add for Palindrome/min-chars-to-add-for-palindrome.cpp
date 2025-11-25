class Solution {
  public:
    int minChar(string &s) {
        // Solving it using KMP
        string temp =s;
        reverse(s.begin(), s.end());
        temp+="#";
        temp+=s;
        vector<int> lps(temp.size(),0);
        int pre=0, suff=1;
        while(suff<temp.size()){
            if(temp[pre]==temp[suff]){
                lps[suff]= pre+1;
                pre++;
                suff++;
            }
            else if(pre==0){
                lps[suff]=0;
                suff++;
            }
            else{
                pre = lps[pre-1];
            }
        }
        int palindrome = lps[suff-1];
        return s.size()-palindrome;
    }
};
