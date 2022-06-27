# 0 - 1 Knapsack Problem 
# https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#User function Template for python3

class Solution:
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        # code here
        dp=[[0]*(W+1) for _ in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,W+1):
                if wt[i-1]<=j:
                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]])
                else:
                    dp[i][j]=dp[i-1][j]
                    
        return dp[n][W]

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        W = int(input())
        val = list(map(int,input().strip().split()))
        wt = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.knapSack(W,wt,val,n))
# } Driver Code Ends