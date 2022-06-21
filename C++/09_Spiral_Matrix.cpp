//54. Spiral Matrix
//Problem Link :- https://leetcode.com/problems/spiral-matrix/description/

//Approach :-
/*
    To traverse the matrix, we can do it in 4 steps. But we need to take care of the fact
    that after a cycle of these 4 steps, the matrix left to traverse gets smaller. Hence we 
    make 4 pointers to define the current boundary of matrix.
    cleft = left boundary(intially 0), cright = right boundary(intially m-1),
    rup = upper boundary(intially 0), rdown = lower boudndary(initially n-1)
    The  steps to traverse the matrix are :-
    1. Traverse from matrix[rup][cleft] to matrix[rup][cright] and then increment rup.
    2. Traverse from matrix[rup][cright] to matrix[rdown][cright] and decrement cright.
    3. Traverse from matrix[rdown][cright] to matrix[rdown][cleft] and and increment rdown.
    4. Traverse from matrix[rdown][cleft] to matrix[rup][cright] and increment cleft.

    We perform these 4 steps until we have completely traversed the matrix.

*/

//Code :-
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        int cleft = 0,cright = m-1;
        int rup = 0,rdown = n-1;
        vector<int>ans;
        while(cleft<=cright && rup<=rdown){
            for(int i=cleft;i<=cright;i++){
                ans.push_back(matrix[rup][i]);
            }
            rup++;
            if(rup>rdown) break;
            for(int i=rup;i<=rdown;i++){
                ans.push_back(matrix[i][cright]);
            }
            cright--;
            if(cright<cleft) break;
            for(int i=cright;i>=cleft;i--){
                ans.push_back(matrix[rdown][i]);
            }
            rdown--;
            if(rdown<rup) break;
            for(int i=rdown;i>=rup;i--){
                ans.push_back(matrix[i][cleft]);
            }
            cleft++;
        }
        return ans;
    }
};