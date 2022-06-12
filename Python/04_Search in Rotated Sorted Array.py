# 33. Search in Rotated Sorted Array
# https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution:
    def search(self, nums, target):
        '''
        start=0
        end=len(nums)-1
        while start<end:
            mid=(start+end)//2
            if nums[mid]>nums[end]:
                start=mid+1
            else:
                end=mid
        rot=start
        start=0
        end=len(nums)-1
        while start<=end:
            mid=(start+end)//2
            realmid=(mid+rot)%len(nums)
            if nums[realmid]==target:
                return realmid
            elif nums[realmid]>target:
                end=mid-1
            else:
                start=mid+1
        return -1
        '''
        
        start=0
        end=len(nums)-1
        while start<=end:
            mid=(start+end)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]>=nums[start]:
                if nums[start]<=target<=nums[mid]:
                    end=mid-1
                else:
                    start=mid+1
            else:
                if nums[mid]<=target<=nums[end]:
                    start=mid+1
                else:
                    end=mid-1
        return -1