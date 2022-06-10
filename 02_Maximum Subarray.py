# 53. Maximum Subarray
# https://leetcode.com/problems/maximum-subarray/

class Solution:
    def maxSubArray(self, nums):
        # Kadane's Algorithm
        ans=nums[0]
        sum=nums[0]
        for i in nums[1:]:
            sum=max(sum+i,i)
            ans=max(ans,sum)
        return ans

        '''
        # Kadane's Algorithm with concise code
        for i in range(1,len(nums)):
            nums[i]=max(nums[i],nums[i-1]+nums[i])
        return max(nums)
        '''
        
        '''
        # Divide & Conquer
        def divncon(nums,start,end):
            if start>end:
                return -float('inf')
            leftsum,rightsum,currsum,mid=0,0,0,(start+end)//2
            for i in range(mid-1,start-1,-1):
                currsum+=nums[i]
                leftsum=max(leftsum,currsum)
            currsum=0
            for i in range(mid+1,end+1):
                currsum+=nums[i]
                rightsum=max(rightsum,currsum)
            return max(divncon(nums,mid+1,end),divncon(nums,start,mid-1),leftsum+nums[mid]+rightsum)

        return divncon(nums,0,len(nums)-1)
        '''

        '''
        # Optimized Divide & Conquer
        pref=nums.copy()
        suf=nums.copy()
        for i in range(1,len(nums)):
            pref[i]+=max(0,pref[i-1])
        for i in range(len(nums)-2,-1,-1):
            suf[i]+=max(suf[i+1],0)

        def divncon(nums,start,end):
            if start>end:
                return -float('inf')
            mid=(start+end)//2
            return max(divncon(nums,start,mid-1),divncon(nums,mid+1,end),pref[mid]+suf[mid]-nums[mid])
        
        return divncon(nums,0,len(nums)-1)
        '''

        '''
        # Dynamic Programming - Tabulation
        dp=[0]*len(nums)
        dp[0]=ans=nums[0]
        for i in range(1,len(nums)):
            dp[i]=nums[i]+max(dp[i-1],0)
            ans=max(ans,dp[i])
        return ans
        '''

'''
# Dynamic Programming - Memoization
ans=0   # global variable
class Solution:
    def maxSubArray(self, nums):
        @lru_cache(None)    # also accepted with-out Memoization 
        def dp(i):
            if i==len(nums):
                return 0
            
            don=nums[i]
            dos=nums[i]+dp(i+1)
            res=max(dos,don)
            global ans 
            ans=max(ans,res)
            return res
        
        global ans
        ans=nums[0]
        dp(0)
        return ans
'''