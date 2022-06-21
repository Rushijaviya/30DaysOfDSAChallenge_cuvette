# 1654. Minimum Jumps to Reach Home
# https://leetcode.com/problems/minimum-jumps-to-reach-home/

from collections import deque

class Solution:
    def minimumJumps(self, forbidden, a, b, x):
        max_val=max([x]+forbidden)+a+b
        jumps=[0]+[float('inf')]*max_val
        for position in forbidden:
            jumps[position]=-1
        queue=deque([0])
        while queue:
            pos=queue.popleft()
            if pos+a<=max_val and jumps[pos+a]>jumps[pos]+1:
                queue.append(pos+a)
                jumps[pos+a]=jumps[pos]+1
            if pos-b>0 and jumps[pos-b]>jumps[pos]+1:
                jumps[pos-b]=jumps[pos]+1
                if pos-b+a<=max_val and jumps[pos-b+a]>jumps[pos]+2:
                    queue.append(pos-b+a)
                    jumps[pos-b+a]=jumps[pos]+2
        return jumps[x] if jumps[x]!=float('inf') else -1