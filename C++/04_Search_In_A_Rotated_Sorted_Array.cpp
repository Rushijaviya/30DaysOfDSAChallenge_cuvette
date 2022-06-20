//33. Search in Rotated Sorted Array
//Problem Link :- https://leetcode.com/problems/search-in-rotated-sorted-array/

// Naive Approach :-
/*
    The brute force approach would be to do a linear search on the array. If we find the target
    we simply return. Otherwise if we reach the end of the array and still haven't found our target, we 
    return -1.
    Time Complexity :- O(N);
    Space Complexity :- O(1);
*/

//Efficient Approach :-
/* 
    The problem can be solved using binary search.The key observation is that after rotation 
    of the array, it is divided into two sorted subarrays. We should also observe that whenver
    we divide the array in half, the middle portion would be a part of either of the sorted subarrays.
    For eg - Initial array = [1,2,3,4,5,6]
             After rotation = [4,5,6,1,2,3] 
             We can see that the subarray [4,5,6] and [1,2,3] are sorted.
    
    We first initialise the low and high pointers to start and end of the array.
    We find the middle of the array and compare it with target. If the value at middle 
    index is equal to target, then we simply return.
    Otherwise two cases arise :-
    Case 1 :- Mid lies in the first sorted subarray(i.e nums[mid] > nums[lo]). In this case
              we check if target lies in this subarray or not. If yes then we reduce 
              our search space to this subarray(hi = mid-1). Otherwise, we search in other half
              (lo = mid+1);
    Case 2 :- Mid lies in the other subarray(i.e nums[mid] < nums[lo]).In this case, we check if
              target lies in this subarray or not. If yes, then we reduce our search space to this 
              subarray(lo = mid+1). Otherwise, we search in other half(hi = mid-1);
    
    Time Complexity :- O(logN);
    Space Complexity :- O(1);
*/

//Code :- 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] >= nums[lo]){
                if(target>=nums[lo] && target<=nums[mid]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[hi]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        
        return -1;
    }
};