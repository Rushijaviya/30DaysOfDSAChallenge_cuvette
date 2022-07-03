// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

void SortedStack ::sort()
{
    // Your code here
    _sort(s);
}

void _sort(stack<int> &s)
{
    stack<int> tempStack;

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > temp)
        {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    s = tempStack;
}