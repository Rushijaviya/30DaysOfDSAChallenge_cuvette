# First non-repeating character in a stream
# https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

from collections import Counter

class Solution:
    def FirstNonRepeating(self, A):
        # Code here
        
        ans=""
        d={}
        main=[]
        for i in A:
            d[i]=d.get(i,0)+1
            if i not in main and d[i]==1:
                main.append(i)
            if i in main and d[i]>1:
                main.remove(i)
            if ans=="" or ans[-1]==i or ans[-1]=='#':
                if main:
                    ans+=main[0]
                else:
                    ans+='#'
            else:
                ans+=ans[-1]
        return ans

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        A = input()
        ob = Solution()
        ans = ob.FirstNonRepeating(A)
        print(ans)

# } Driver Code Ends