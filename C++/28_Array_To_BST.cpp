// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1

class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> ans;
        fillArray(ans, 0, nums.size() - 1, nums);
        return ans;
    }
    
    void fillArray(vector<int>& ans, int start, int end, vector<int>& nums)
    {
        if(start > end)
            return;
            
        int mid = (start + end)/2;
        ans.push_back(nums[mid]);
        fillArray(ans, start, mid - 1, nums);
        fillArray(ans, mid + 1, end, nums);
    }
};
