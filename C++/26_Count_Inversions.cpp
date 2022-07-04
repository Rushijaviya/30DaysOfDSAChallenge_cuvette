// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }

    long long mergeSort(long long arr[], long long temp[], int start, int end)
    {
        if(start >= end)
            return 0;
        
        long long count = 0;
        int mid = (start + end)/2;
        count = mergeSort(arr, temp, start, mid);
        count += mergeSort(arr, temp, mid + 1, end);
        count += merge(arr, temp, start, mid, end);
    
        return count;
    }

    long long merge(long long arr[], long long temp[], int start, int mid, int end)
    {
        long long count = 0;
    
        int i = start, j = mid + 1, k = start;
    
        while(i <= mid && j <= end)
        {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
            {
                temp[k++] = arr[j++];
                count += mid + 1 - i;
            }
        }
    
        while(i <= mid)
            temp[k++] = arr[i++];
        while(j <= end)
            temp[k++] = arr[j++];
        
        for(int i = start; i <= end; ++i)
            arr[i] = temp[i];
        
        return count;
    }
};
