/* Stock buy and sell */
/* https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1 */

//Approach :-
/*
 *  The basic observation in this problem is that whenever we buy a stock, we will hold that stock until the value of the stock increases.
 *  Once the value of stock decreases than the value at previous day, we sell the stock and buy again with the decreased value.
 *  This can also be seen as : We need to find all the increasing subarrays in the given array. The starting index of the subarray denote
 *  the days when we will buy the stock,and the ending index denote when we will sell the stock.
 *  Time Complexity :- O(N)
 *  Space Complexity :- O(1)
*/


// Code:-

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        int buyIndex = 0;
        int sellIndex = 1;
        vector<vector<int>>res;
        while(sellIndex<n){
            if(A[sellIndex]>A[sellIndex-1]){
                ++sellIndex;
            }
            else{
                if(sellIndex-1 > buyIndex) res.push_back({buyIndex,sellIndex-1});
                buyIndex = sellIndex;
                ++sellIndex;
            }
        }
        if(sellIndex-1 > buyIndex) res.push_back({buyIndex,sellIndex-1});
        //for(int i=0;i<res.size();i++) cout<<res[i][0]<<" "<<res[i][1]<<endl;
        return res;
    }
};
