# 225. Implement Stack using Queues
# https://leetcode.com/problems/implement-stack-using-queues/

class MyStack:

    def __init__(self):
        self.q1=[]

    def push(self, x):
        self.q1.append(x)

    def pop(self):
        temp=[]
        while len(self.q1)>1:
            temp.append(self.q1.pop(0))
        x=self.q1.pop()
        self.q1=temp
        return x

    def top(self):
        return self.q1[-1]

    def empty(self):
        return len(self.q1)==0

'''
class MyStack:

    def __init__(self):
        self.q1=[]

    def push(self, x):
        self.q1.append(x)
        count=len(self.q1)
        while count>1:
            self.q1.append(self.q1.pop(0))
            count-=1

    def pop(self):
        return self.q1.pop(0)

    def top(self):
        return self.q1[0]

    def empty(self):
        return len(self.q1)==0
'''

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()