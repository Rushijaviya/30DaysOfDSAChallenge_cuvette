// # https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum =v[0];
        int maxm = v[0];
        int n = v.size();
        for(int i=1;i<n;i++){
            if(sum+v[i]<v[i]){
                sum=v[i];
                maxm=max(sum,maxm);
            }else{
                sum+=v[i];
                maxm=max(sum,maxm);
            }
        }
        return max(sum,maxm);
    }
};