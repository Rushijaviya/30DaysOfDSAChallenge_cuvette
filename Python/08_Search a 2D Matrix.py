# 74. Search a 2D Matrix
# https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution:
    def searchMatrix(self, matrix, target):

        def binsearch(l,tar):
            start,end=0,len(l)-1
            while start<=end:
                mid=(start+end)//2
                if l[mid]==tar:
                    return True
                elif l[mid]>tar:
                    end=mid-1
                else:
                    start=mid+1
            return False
        
        startrow=0
        endrow=len(matrix)-1
        endcol=len(matrix[0])-1
        while startrow<=endrow:
            mid=(startrow+endrow)//2
            if matrix[mid][0]<=target and matrix[mid][endcol]>=target:
                if binsearch(matrix[mid],target):
                    return True
                else:
                    return False
            elif matrix[mid][0]>target:
                endrow=mid-1
            else:
                startrow=mid+1
        return False
        
        '''
        for row in matrix:
            if row[-1] >= target:
                return target in row
        return False
        '''

        '''
        return any(target in row for row in matrix)
        '''