/* Egg Dropping Puzzle */ 
/* https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1 */


// Approach :- 
/*
 * We are given N eggs and K floors, and we need to find the highest floor from where if we dropp an egg, it will surely not break.  
 * We can solve the problem recursively, by defining a function solve(N,K) which returns the result for N eggs and K floors. Inside 
 * the function, we check for every floor from 1 to K and consider 2 cases :- Either the egg breaks or it does not. If the egg breaks,
 * then that means it can be either this floor or a floor beneath this floor. So, we call for solve(N-1,curFloor-1). If the egg does not 
 * break, that means it will be a floor above the current floor which we are looking at. Hence, we call for solve(N,k-curFloor). 
 * We need to return the max of these two calls, since we are looking for the highest floor. Also, of all the floors from 1 to k, 
 * we need to return the minimum number of attempts.
 * The above brute force solution gives exponential time complexity. We can optimise it by using a dp array to keep track of results we 
 * calculated and use later on.(Memoisation).
 * Time Complexity :- O(N*K²);
 */


// Code :-

class Solution
{   
    private:
    int solve(int n,int k,vector<vector<int>> &dp){
        if(k==1 || k==0) return k;
        
        if(n==1) return k;
        
        if(dp[n][k]!=-1) return dp[n][k];
        int res = INT_MAX;
        int curFloor = 1;
        while(curFloor<=k){
            res = min(res,max(solve(n-1,curFloor-1,dp),solve(n,k-curFloor,dp)));
            ++curFloor;
        }
        return dp[n][k]=res+1;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(1005,vector<int>(1005,-1));
        return solve(n,k,dp);
    }
};
