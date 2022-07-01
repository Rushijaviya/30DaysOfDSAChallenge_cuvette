/* Vertical Traversal Of A Binary Tree */
/* https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1 */


// Approach :-
/******************************************************************************************************************************************
 *  We can solve the problem by assigning coordinates to each node with referecence to the root node. All nodes to the left of root
 *  node have negative x coordinates, and all nodes to the right have positive x coordinates. ALso,  the y coordinates represents the level
 *  of the nodes. We perform an inorder traversal of the tree and store the nodes along with their coordinates. The vertical traversal 
 *  of tree will be in order of x coordinates, and for nodes with same x coordinates, we will follow order of y coordinates.
 *                  
 *              -2 -1  0  1  2      <--x
 *   
 *                     1              0       
 *                   /   \
 *                  2     3           1
 *                /   \ /   \
 *               4    5 6    7        2 
 *                                    ^
 *                                    |
 *                                    y
 *
 *  Vertical Traversal :-  4  {-2,2}
 *                         2  {-1,1} 
 *                         1  {0,0}
 *                         5  {0,1}
 *                         6  {0,2} 
 *                         3  {1,1}
 *                         7  {2,2}
 * ****************************************************************************************************************************************/


// Code :- 

class Solution
{   
    private:
    map<int,map<int,vector<int>>>m;
    void inorder(Node* root,int x,int y){
        if(root==NULL) return;
        m[x][y].push_back(root->data);
        inorder(root->left,x-1,y+1);
        inorder(root->right,x+1,y+1);
    }
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        inorder(root,0,0);
        vector<int>res;
        for(auto it: m){
            for(auto it1:it.second){
                vector<int>s = it1.second;
                for(auto it2:s){
                    res.push_back(it2);
                }
            }
        }
        return res;
    }
};
