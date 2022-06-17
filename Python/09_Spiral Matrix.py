# 54. Spiral Matrix
# https://leetcode.com/problems/spiral-matrix/description/

class Solution:
    def spiralOrder(self, matrix):
        def sprial(l):
            ans=[]
            row,col=len(l),len(l[0])
            for i in range(col):
                ans.append(l[0][i])
            for i in range(1,row):
                ans.append(l[i][col-1])
            if row!=1:
                for i in range(col-2,-1,-1):
                    ans.append(l[row-1][i])
            if col!=1:
                for i in range(row-2,0,-1):
                    ans.append(l[i][0])
            return ans

        ans=sprial(matrix)
        temp=matrix.copy()
        while temp:
            l=[]
            try:
                temp.pop()
                temp.pop(0)
                for i in range(len(temp)):
                    temp[i].pop(0)
                    temp[i].pop()
                l=sprial(temp)
                for i in l:
                    ans.append(i)
            except:
                pass
        return ans