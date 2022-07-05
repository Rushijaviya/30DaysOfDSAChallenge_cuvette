# 653. Two Sum IV - Input is a BST
# https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findTarget(self, root, k):
        '''
        def inorder(root):
            if not root:
                return []
            return inorder(root.left)+[root.val]+inorder(root.right)
        
        l=inorder(root)
        left=0
        right=len(l)-1
        while left<right:
            if l[left]+l[right]==k:
                return 1
            elif l[left]+l[right]>k:
                right-=1
            else:
                left+=1
        return 0
        '''
        
        '''
        s=set()
        queue=[root]
        while queue:
            node=queue.pop(0)
            if k-node.val in s:
                return 1
            s.add(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return 0
        '''
        
        '''
        # Time: O(N), where N is the number of nodes in the BST.
        # Space: O(H), where H is the height of the BST, it's the depth stack recursion.
        def inorder(root):
            if root:
                yield from inorder(root.left)
                yield root.val
                yield from inorder(root.right)
        
        def reversedinorder(root):
            if root:
                yield from reversedinorder(root.right)
                yield root.val
                yield from reversedinorder(root.left)
        
        leftGenerator = inorder(root)
        rightGenerator = reversedinorder(root)

        left=next(leftGenerator)
        right=next(rightGenerator)
        while left<right:
            if left+right==k:
                return 1
            elif left+right>k:
                right=next(rightGenerator)
            else:
                left=next(leftGenerator)
        return 0
        '''

        # Time: O(N), where N is the number of nodes in the BST.
        # Space: O(H), where H is the height of the BST. The size of stack is up to O(H).
        def pushLeft(st,root):
            while root:
                st.append(root)
                root=root.left
        
        def pushRight(st,root):
            while root:
                st.append(root)
                root=root.right
        
        def nextLeft(st):
            node=st.pop()
            pushLeft(st,node.right)
            return node.val
        
        def nextRight(st):
            node=st.pop()
            pushRight(st,node.left)
            return node.val

        stLeft,stRight=[],[]
        pushLeft(stLeft,root)
        pushRight(stRight,root)
        left,right=nextLeft(stLeft),nextRight(stRight)
        while left<right:
            if left+right==k:
                return 1
            elif left+right>k:
                right=nextRight(stRight)
            else:
                left=nextLeft(stLeft)
        return 0