# Nth Fibonacci Number
# https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

#User function Template for python3
class Solution:
    def nthFibonacci(self, n):
        # code here
        '''
        if n==0:
            return 0
        def dp(i):
            if i<=2:
                return 1
            if i in memo:
                return memo[i]
            memo[i]=dp(i-1)+dp(i-2)
            return memo[i]
        memo={}
        return dp(n)%1000000007
        '''
        
        if n==0:
            return 0
        x,y=0,1
        for i in range(2,n+1):
            x,y=y,x+y
        return y%1000000007

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.nthFibonacci(n))
# } Driver Code Ends