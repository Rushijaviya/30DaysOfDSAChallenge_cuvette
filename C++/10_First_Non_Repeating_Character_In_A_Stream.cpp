// # First non-repeating character in a stream
// # https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

//Approach :-
/*
    To find the first non-repeating character in a stream, we need to create a hash which would
    store the count of each character in the stream uptill now. We will also have a queue the front
    element of which always stores the first non repeating character.
    We iterate through the string given,and push the current character in our queue. Then we increment
    the count of current character by 1.Now we look at the front element of queue. If the count
    of front element is greater than 1, we pop it since it cannot be a non repeating character. We 
    continue this process until we find an element with count = 1(which would be the ans), or the queue 
    becomes empty in which case no non repeating character exists.

    Time Complexity :- O(N)
    Space Complexity :- O(N)
*/

//Code :- 
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int n = A.length();
		    vector<int>count(26,0);
		    queue<char>q;
		    string res;
		    for(int i=0;i<n;i++){
		        q.push(A[i]);
		        count[A[i]-'a']++;
		        while(!q.empty() && count[q.front()-'a']>1){
		            q.pop();
		        }
		        res.push_back((q.empty()?'#':q.front()));
		    }
		    
		    return res;
		}

};