void connect(Node *root)
    {
       // Your Code Here
       if(!root)
       return;
       queue<Node*>q;
       Node* temp=root;
       q.push(temp);
       while(!q.empty()){
           int n=q.size();
           queue<Node*>p;
           for(int i=0;i<n;i++){
               Node* t=q.front();
               q.pop();
               t->nextRight=q.empty()?NULL:q.front();
               if(t->left)
               p.push(t->left);
               if(t->right)
               p.push(t->right);
           }
           while(!p.empty()){
               q.push(p.front());
               p.pop();
           }
       }
    }    
