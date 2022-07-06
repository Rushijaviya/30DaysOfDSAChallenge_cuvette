# Array to BST 
# https://practice.geeksforgeeks.org/problems/array-to-bst4443/1

class Solution:
    def sortedArrayToBST(self, nums):
        # code here
        def solve(start,end,ans):
            if start>end:
                return
            mid=(start+end)//2
            ans.append(nums[mid])
            solve(start,mid-1,ans)
            solve(mid+1,end,ans)
            
        ans=[]
        solve(0,len(nums)-1,ans)
        return  ans

#{ 
#  Driver Code Starts
if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n = int(input())
        nums = list(map(int, input().split()))
        obj = Solution()
        ans = obj.sortedArrayToBST(nums)
        for _ in ans:
            print(_, end = " ")
        print()

# } Driver Code Ends