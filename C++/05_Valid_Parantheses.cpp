//20. Valid Parentheses
//Problem Link :- https://leetcode.com/problems/valid-parentheses/

//Approach :- 
/*
    To check whether the given parantheses sequence is valid or not, we will use a stack.
    We simply traverse through the string and :-
    1. If the current char is an open bracket(i.e '(','{','[') we simply push it on the stack.
    2. If the current char is a closed bracket, we check if the topmost element of the stack is an 
    open bracket of the same type or not. If yes, then we pop it from the stack, otherwise it means 
    that the given parantheses is not valid and we return false. 
    3. After we traverse the complete string, if the stack remains empty then we return true, 
    otherwise false.

    Time Complexity :- O(N)
*/

class Solution {
public:
    bool isValid(string s) {
        int n = (int)s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return (st.empty()?true:false);
    }
};