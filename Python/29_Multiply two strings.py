# Multiply two strings 
# https://practice.geeksforgeeks.org/problems/multiply-two-strings/1

#User function Template for python3

class Solution:
    def multiplyStrings(self,s1,s2):
        # code here
        # return the product string
        
        '''
        return int(s1)*int(s2)
        '''
        
        flag=0
        if s1[0]=='-' and s2[0]=='-':
            s1=s1[1:]
            s2=s2[1:]
        elif s1[0]=='-':
            s1=s1[1:]
            flag=1
        elif s2[0]=='-':
            s2=s2[1:]
            flag=1
        ans=0
        count=0
        for i in range(len(s2)-1,-1,-1):
            carry=0
            result=[]
            for j in range(len(s1)-1,-1,-1):
                temp=int(s1[j])*int(s2[i])+carry
                carry=0
                if temp>=10:
                    carry=temp//10
                    temp=temp%10
                result.append(temp)
            if carry:
                result.append(carry)
            result = int("".join(str(i) for i in result[::-1]))
            ans+=(result*(10**count))
            count+=1
        return -ans if flag else ans

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        a,b=input().split()
        print(Solution().multiplyStrings( a.strip() , b.strip() ))

# } Driver Code Ends