// Nth Fibonacci Number
// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

//Approach 1 (Iterative) :-
/*
    We know that fib[0] = 0 and fib[1] = 1. We also know that fib[n] = fib[n-1]+fib[n-2]. We can iteratively calculating fib[i] starting  from i = 2 up until n. Then we simply return the res.
    Time Complexity :- O(N)

    //Code :-
    class Solution {
    private:
    const long long int MOD = 1e9+7;
    public:
        long long int nthFibonacci(long long int n){
            // code here
            long long int fib0 = 0;
            long long int fib1 = 1;
            long long int cur;
            for(int i=2;i<=n;i++){
                cur = (fib0%MOD + fib1%MOD)%MOD;
                fib0 = fib1;
                fib1 = cur;
            }
            return cur;
        }
    };
*/

//Approach 2(Recursive + Memoisation) :-
/*
    We can define a function solve(n) which returns the nth fibonacci number, which would be solve(n-1)+solve(n-2).We can also create a memo array where we store the result of each step and use it later on when we need the result.
    Time Complexity :- O(N)
*/

//Code :-
class Solution {
private:
const long long int mod = 1e9+7;
  public:
    long long int solve(int n,vector<long long int> &dp){
        if(n==0) return 0;
        if(n<=2) return 1;
        
        if(dp[n]!=-1) return dp[n]%mod;
        return dp[n] = (solve(n-1,dp)%mod + solve(n-2,dp)%mod)%mod;
    }
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int>dp(1005,-1);
        return solve(n,dp);
    }
};