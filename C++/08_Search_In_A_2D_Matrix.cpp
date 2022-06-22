//74. Search a 2D Matrix
//Problem Link :- https://leetcode.com/problems/search-a-2d-matrix/

//Approach 1 :-
/*
    Since the matrix given to us is sorted, we can use binary search to find the solution.
    We first perform a binary search on the last column of the matrix to find the cell with 
    the smallest value larger than the target element. This helps us to pin down the row in which 
    target element could exist. Then we apply a simple binary search on this row to find whether target 
    element exists in the row or not.
    Time Complexity :- O(logN + logM)
    Space Complexity :- O(1)

    **Note :- In the problem statement on Leetcode it is mentioned that "The first integer of each row 
    is greater than the last integer of the previous row." If this was not the case, and only the
    individual rows were sorted, this method would have given the wrong result. In that case, approach 2
    is suitable.
    
    Code :-
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = (int)matrix.size();
            int m = (int)matrix[0].size();
            int lo = 0;
            int hi = n-1;
            int row = -1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(matrix[mid][m-1] == target){
                    return true;
                }
                else if(matrix[mid][m-1]>target){
                    row = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            if(row==-1){
                return false;
            }
            lo = 0;
            hi = m-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(matrix[row][mid]==target){
                    return true;
                }
                else if(matrix[row][mid]>target){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            return false;
        }
    }; 
*/

//Approach 2 :-
/*
    We can also use another approach to solve the problem. 
    In this approach we start at the upper-right(i=0 and j=m-1) corner of the matrix and compare it with the
    target element. We can have three cases :-
    1. If the current element is equal to target element, we simply return true.
    2. If the current element is smaller than target element, we move one row down (i.e i++)
    3. If the current element is larger than target element, we move one column left (i.e j--)
    We repeat the steps until the pointers move outside the matrix, in which case the target element
    doesn't exist in the matrix and we return false.
    Time Complexity :- O(M+N)
    Space Complexity :- O(1)
*/

//Code :- 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        int i = 0;int j = m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        
        return false;
    }
};