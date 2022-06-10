// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1/

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int fre[3]={0,0,0};
        for(int i =0;i<n;i++) fre[a[i]]++;
        int i;
        for(i=0;i<fre[0];i++) a[i]=0;
        for(;fre[1]--;i++) a[i]=1;
        for(;i<n;i++) a[i]=2;
    }
    
};
