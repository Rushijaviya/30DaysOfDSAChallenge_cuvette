/* Left View of Binary Tree */ 
/* https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1 */


// Approach :-
/*
 * The left view of binary tree will contain all nodes, which are first from the left of the binary tree at each level.
 * For eg :-        4              <--Level 0
 *                 /  \            
 *                5    2           <--Level 1
 *                    / \
 *                   6   3         <--Level 2
 *                  /
 *                 7               <--Level 3
 *
 * In the above tree, we can see that nodes 4, 5, 6 and 7 are the first nodes from the left at levels 0,1,2 and 3 respectively.
 * We can solve the problem recursively, by defining a function which goes to the left and the right of every node, until it reaches a 
 * NULL node, and checks if the current node is first node of the level. If yes, then store it in the res vector.
 * Time Complexity :- O(N)
 */

// Code:-
void solve(Node* root,vector<int>& res,int level){
    if(root==NULL) return;
    
    if(level == (int)res.size()){
        res.push_back(root->data);
    }
    solve(root->left,res,level+1);
    solve(root->right,res,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>res;
   solve(root,res,0);
   return res;
}
