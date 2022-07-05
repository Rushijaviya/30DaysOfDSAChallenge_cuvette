// 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Approach 1 :
/*
    We know that inorder traversal of a BST gives us all the elements of a BST in sorted
    order. Hence, we first perform inorder traversal of BST and store it in a vector. Then
    we can search for target number in our sorted vector using two pointers.
    Time Complexity:- O(N)
    Space Complexity:- O(N);

    //Code :-
    class Solution {
    private:
        void inorder(TreeNode* root,vector<int>& nums){
            if(root==NULL) return;
            inorder(root->left,nums);
            nums.push_back(root->val);
            inorder(root->right,nums);
        }
    public:
        bool findTarget(TreeNode* root, int k) {
            vector<int>nums;
            inorder(root,nums);
            int i = 0,j = (int)nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]==k) return true;
                else if(nums[i]+nums[j]>k) --j;
                else ++i;
            }
            return false;
        }
    };
*/

// Approach 2 :-
/*
    The first approach needs O(N) space to store all elements in BST while doing inorder
    traversal. We can optimise the space complexity by using a BST Iterator. The job of BST
    Iterator is to give us the next element which comes in the inorder traversal of BST and
    also in the reverse-inorder traversal in a BST. Hence, we first initialise two pointers, pointing to first values in inorder and reverse-inorder traversal of BST. Then we simply use the two pointer approach to check whether target
    sum exists in BST or not. Since we are using the BST Iterator, we would be storing at
    max O(h) elements at a given time.

    BST Iterator :- https://leetcode.com/problems/binary-search-tree-iterator/
    Solution to BST Iterator problem :- https://leetcode.com/submissions/detail/739303870/

    Time Complexity :- O(N)
    Space Complexity :- O(h), where h is height of BST
*/

// Code :-

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator
{
private:
    stack<TreeNode *> nextS;
    stack<TreeNode *> prevS;

public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *cur1 = root;
        TreeNode *cur2 = root;
        while (cur1 != NULL)
        {
            nextS.push(cur1);
            cur1 = cur1->left;
        }
        while (cur2 != NULL)
        {
            prevS.push(cur2);
            cur2 = cur2->right;
        }
    }
    bool hasNext()
    {
        return !nextS.empty();
    }
    bool hasPrev()
    {
        return !prevS.empty();
    }
    int next()
    {
        TreeNode *res = nextS.top();
        int resVal = res->val;
        nextS.pop();
        res = res->right;
        while (res != NULL)
        {
            nextS.push(res);
            res = res->left;
        }
        return resVal;
    }
    int prev()
    {
        TreeNode *res = prevS.top();
        int resVal = res->val;
        prevS.pop();
        res = res->left;
        while (res != NULL)
        {
            prevS.push(res);
            res = res->right;
        }
        return resVal;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator it1 = BSTIterator(root);
        int i = it1.next();
        int j = it1.prev();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j > k)
                j = it1.prev();
            else
                i = it1.next();
        }
        return false;
    }
};