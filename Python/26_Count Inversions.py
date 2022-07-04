# Count Inversions 
# https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution:
    #User function Template for python3
    
    # arr[]: Input Array
    # N : Size of the Array arr[]
    #Function to count inversions in the array.
    
    def helperCount(self,arr,low,mid,high):
        
        n1 = mid-low+1
        n2 = high-mid
        # Left sorted array
        left = []
        for i in range(n1):
            left.append(arr[low+i])  
        # Right sorted array
        right = []
        for j in range(n2):
            right.append(arr[mid+1+j])
        # Merging two sorted array
        l,r,k = 0,0,low
        res = 0
        while l<n1 and r<n2:
            if left[l]<=right[r]:
                arr[k] = left[l]
                l += 1
            else:
                arr[k] = right[r]
                r +=1
                res = res+(n1-l)
            k +=1
        while l<n1:
            arr[k] = left[l]
            l += 1
            k +=1
        while r<n2:
            arr[k] = right[r]
            r +=1
            k +=1
        return res
        
        
    def mergeP(self,arr,low,high):
        if low<high:
            mid=(low+high)//2
            l=self.mergeP(arr,low,mid)
            r=self.mergeP(arr,mid+1,high)
            m=self.helperCount(arr,low,mid,high)
            
            return l+r+m
        return 0
    
    def inversionCount(self, arr, n):
        # Your Code Here
        return self.mergeP(arr,0,n-1)
                
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for tt in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a,n))
# } Driver Code Ends