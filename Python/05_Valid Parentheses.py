# 20. Valid Parentheses
# https://leetcode.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s):
        d={'(':')','{':'}','[':']'}
        stack=[]
        for i in s:
            if i in d:
                stack.append(d[i])
            elif not stack or stack.pop()!=i:
                return False
        return len(stack)==0

        '''
        stack=[]
        for i in s:
            if i in "({[":
                stack.append(i)
            elif i==')':
                if not stack or stack.pop()!='(':
                    return False
            elif i==']':
                if not stack or stack.pop()!='[':
                    return False
            else:
                if not stack or stack.pop()!='{':
                    return False
        return len(stack)==0
        '''