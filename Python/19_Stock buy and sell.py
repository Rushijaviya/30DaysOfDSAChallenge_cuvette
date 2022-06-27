# Stock buy and sell
# https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

#User function template for Python

class Solution:
    #Function to find the days of buying and selling stock for max profit.
    def stockBuySell(self, A, n):
        #code here
        result = []
        #Prices must be given for at least two days else return the empty result.
        if(n==1):
            return result
        i=0
        cnt=0
        #Traversing through given price array.
        while(i<n-1):
            #Finding Local Minima. Note that the limit of loop is (n-2)
            #as we are comparing present element to the next element.
            while((i<n-1) and (A[i+1]<=A[i])):
                i=i+1

            #If we reach the end, we break the loop as no further
            #solution is possible.
            if(i==n-1):
                break
                
             # e[0] denotes buy , e[1] denotes sell    
            e=[0,0] 
            #Storing the index of minima which gives the day of buying stock.
            e[0]=i
            i=i+1

            #Finding Local Maxima. Note that the limit of loop is (n-1)
            #as we are comparing present element to previous element.
            while((i<n) and A[i]>=A[i-1]):
                i=i+1
            #Storing the index of maxima which gives the day of selling stock.
            e[1]=i-1
            
            #Storing the buy/sell pairs in a list.
            result.append([e[0],e[1]])

            #Incrementing count of buy/sell pairs.
            cnt=cnt+1
        if(cnt==0):
            return []
        else:
            #returning the result.
            return result
        
#{ 
#  Driver Code Starts
#Initial template for Python

def check(ans,A,p):
    c = 0
    for i in range(len(ans)):
        c += A[ans[i][1]]-A[ans[i][0]]
    if(c==p):
        return 1 
    else:
        return 0

if __name__=='__main__':
    t = int(input())
    while(t>0):
        n = int(input())
        A = [int(x) for x in input().strip().split()]
        ob = Solution()
        ans = ob.stockBuySell(A,n)
        p=0
        for i in range(n-1):
            p += max(0,A[i+1]-A[i])
        if(len(ans) == 0):
            print("No Profit",end="")
        else:
            print(check(ans,A,p),end="")
        print()
        t-=1
# } Driver Code Ends