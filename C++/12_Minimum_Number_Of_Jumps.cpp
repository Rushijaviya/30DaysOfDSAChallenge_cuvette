// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here

        if (n == 1)
            return 0;
        if (arr[0] == 0)
            return -1;

        int jump = 1;
        int step = arr[0];
        int reach = arr[0];

        for (int i = 1; i < n; ++i)
        {
            if (i == n - 1)
                return jump;

            reach = max(reach, i + arr[i]);
            step--;

            if (step == 0)
            {
                jump++;
                if (i >= reach)
                    return -1;
                step = reach - i;
            }
        }
        return -1;
    }
};