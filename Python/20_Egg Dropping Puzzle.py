# Egg Dropping Puzzle 
# https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#User function Template for python3

class Solution:
    
    #Function to find minimum number of attempts needed in 
    #order to find the critical floor.
    def eggDrop(self,n, k):
        # code here
        dp=[[-1]*(k+1) for _ in range(n+1)]
        def solve(n,k):
            if dp[n][k]!=-1:
                return dp[n][k]
            if n==0:
                return 0
            if k==0 or k==1 or n==1:
                return k
            ans=float('inf')
            for i in range(1,k+1):
                eggbreak=solve(n-1,i-1)
                eggnotbreak=solve(n,k-i)
                ans=min(ans,max(eggbreak,eggnotbreak))
            dp[n][k]=ans+1
            return dp[n][k]

        return solve(n,k)

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
        n,k = map(int,input().strip().split())
        ob=Solution()
        print(ob.eggDrop(n,k))
# } Driver Code Ends