class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node *temp = q.front();
            
            if(temp == NULL)
            {
                v.push_back(-1);
                q.pop();
            }   
            
            else
            {
                v.push_back(temp -> data);
                q.pop();
            
                q.push(temp -> left);
                q.push(temp -> right);
            }
        }
        
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
        Node *root = new Node(A[0]);
        int n = A.size(), i = 1;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            
            if(A[i] == -1)
                temp -> left = NULL;
            else
            {
                temp -> left = new Node(A[i]);
                q.push(temp -> left);
            }
            
            i++;    
            
            if(A[i] == -1)
                temp -> right = NULL;
            else
            {
                temp -> right = new Node(A[i]);
                q.push(temp -> right);
            }
            
            i++;
        }
       
        return root;
    }
};
