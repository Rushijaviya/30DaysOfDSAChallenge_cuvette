long long maxSubarraySum(int arr[], int n)
{
    long long sum=0;
    long long maxm = -1e18;
    for(int i=0;i<n;i++){
        maxm = (maxm<sum?sum:maxm);
        if(sum+arr[i]<arr[i]){
            sum = arr[i];
        }else sum+=arr[i];
        
    }
     maxm = (maxm<sum?sum:maxm);
      return maxm;
}
