void serial(Node* root,vector<int>&v){
        if(!root){
            v.push_back(-1);
        return ;
        }
        v.push_back(root->data);
        serial(root->left,v);
        
        serial(root->right,v);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
         serial(root,ans);
         return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* solve(vector<int>&v,int* i){
        if(*i==v.size() || v[*i]==-1){
            *i+=1;
        return NULL;
        }
        Node* root=new Node(v[*i]);
        *i+=1;
        root->left=solve(v,i);
        root->right=solve(v,i);
        return root;
    }
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int i=0;
       return solve(A,&i);
    }
