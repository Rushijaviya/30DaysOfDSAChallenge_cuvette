// 0 - 1 Knapsack Problem
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/?page=1&category[]=Dynamic%20Programming&sortBy=submissions#


//Memoisation Approach :-
/*
    We iterate through all the items given, and for each item we have 2 choices :- either 
    we put it into our knapsack or we do not. If we put it into our knapsack, the weight
    of our knapsack decreases by the weight of the item and we add value of the item to our
    profit. For the other case, we simply skip the item without any change to the weight of
    knapsack or profit. 
    We define a recursive function which does the same. Since without applying dp, the time
    complexity would be exponential, we also keep a memo array to store the result at every
    step and before making recursive calls check if we have the answer pre calculated or 
    not and use it accordingly. This makes the time complexity of the solution quadratic.

    Time Complexity :- O(N*W)
    Space Complexity :- O(N*W)
*/

//Code :-
class Solution
{
    private:
    int dp[1005][1005];
    public:
    int solve(int W,int wt[],int val[],int n){
        if(W==0 || n==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        
        if(wt[n-1]<=W){
            return dp[n][W] = max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
        }
        else{
            return dp[n][W] = solve(W,wt,val,n-1);
        }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       return solve(W,wt,val,n);
    }
};

//Tabulation Approach :-
//Code :-
/*
    class Solution
    {
        public:
        //Function to return max value that can be put in knapsack of capacity W.
        int knapSack(int W, int wt[], int val[], int n) 
        { 
        // Your code here
        int dp[n+1][W+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else{
                    if(wt[i-1]<=j){
                        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][W];
        }
    };
*/