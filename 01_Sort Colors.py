# 75. Sort Colors
# https://leetcode.com/problems/sort-colors/

class Solution:
    def sortColors(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        red,white,blue=0,0,len(nums)-1
        while white <= blue:
            if nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                white += 1
                red += 1
            elif nums[white] == 1:
                white += 1
            else:
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1

        '''
        for i in range(len(nums)):
            k=i
            for j in range(i+1,len(nums)):
                if nums[k]>nums[j]:
                    k=j
            nums[i],nums[k]=nums[k],nums[i]
        '''

        '''
        for i in range(1,len(nums)):
            m=nums[i]
            j=i-1
            while j>=0 and nums[j]>m:
                nums[j+1]=nums[j]
                j-=1
            nums[j+1]=m
        '''
        
        '''
        for i in range(len(nums)):
            for j in range(len(nums)-i-1):
                if nums[j]>nums[j+1]:
                    nums[j],nums[j+1]=nums[j+1],nums[j]
        '''