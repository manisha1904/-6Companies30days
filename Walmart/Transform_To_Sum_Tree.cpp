int solve(Node* node){
        if(!node)
        return 0;
        if(!node->left && !node->right){
            int temp=node->data;
            node->data=0;
            return temp;
        }
        int left=0,right=0;
        if(node->left)
         left=solve(node->left);
        if(node->right)
         right=solve(node->right);
         int t=node->data;
         node->data=left+right;
         return t+node->data; 
    }
    void toSumTree(Node *node)
    {
        // Your code here
        if(!node)
        return;
        if(!node->left && !node->right){
            node->data=0;
            return;
        }
        solve(node);
        
    }
