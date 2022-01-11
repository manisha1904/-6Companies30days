//Paritally accepted

class Solution {
  public:
  class Node{
      public:
        int data;
        Node* left;
        Node* right;
        int height;
    };
    Node* newNode(int key){
        Node* root=new Node();
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        root->height=1;
        return root;
    }
    int heightOfAVL(Node* root){
        if(!root)
        return 0;
        return root->height;
    }
    
    int getBalance(Node* root){
        if(!root)
        return 0;
        return heightOfAVL(root->left)-heightOfAVL(root->right);
    }
    
    Node* leftRotate(Node* root){
        Node* right_Part=root->right;
        Node* left_Of_Right=right_Part->left;
        
        right_Part->left=root;
        root->right=left_Of_Right;
        
        root->height=1+max(heightOfAVL(root->left),heightOfAVL(root->right));
        right_Part->height=1+max(heightOfAVL(right_Part->left),heightOfAVL(right_Part->right));
        
        return right_Part;
    }
    
    Node* rightRotate(Node* root){
        Node* left_Part=root->left;
        Node* right_Of_Left=left_Part->right;
        
        left_Part->right=root;
        root->left=right_Of_Left;
        
        root->height=1+max(heightOfAVL(root->left),heightOfAVL(root->right));
        left_Part->height=1+max(heightOfAVL(left_Part->left),heightOfAVL(left_Part->right));
        
        return left_Part;
    }
    
    
    Node* insertNode(Node* root,int key){
        if(!root){
            return newNode(key);
        }
        if(root->data<key)
        root->right=insertNode(root->right,key);
        else if(root->data>key)
        root->left=insertNode(root->left,key);
        else
        return root;
        
        root->height=1+max(heightOfAVL(root->left),heightOfAVL(root->right));
        int balance=getBalance(root);
        
        if(balance>1 && key<root->left->data)
        return rightRotate(root);
        if(balance>1 && key>root->left->data){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance<-1 && key>root->right->data)
        return leftRotate(root);
        if(balance<-1 && key<root->right->data){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    
    int maxValue(Node* root){
        if(!root)
        return INT_MIN;
        int ans=root->data;
        int l=maxValue(root->left);
        int r=maxValue(root->right);
        ans=max(ans,max(l,r));
        return ans;
    }
    
    Node* minValueNode(Node* root){
        Node* current=root;
        while(current->left)
            current=current->left;
        return current;
    }
    
    Node* deleteNode(Node* root,int key){
        if(!root)
        return NULL;
        if(root->data<key)
        root->right=deleteNode(root->right,key);
        else if(root->data>key)
        root->left=deleteNode(root->left,key);
        else{
            if(root->left==NULL || root->right==NULL){
                Node* temp=(root->left)?root->left:root->right;
                if(!temp){
                    temp=root;
                    root=NULL;
                }
                else{
                    *root= *temp;
                }
                free(temp);
            }
            else{
                Node* temp=minValueNode(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
        if(!root)
        return root;
        
        root->height=1+max(heightOfAVL(root->left),heightOfAVL(root->right));
        int balance=getBalance(root);
        
        if(balance>1 && getBalance(root->left)>=0)
        return rightRotate(root);
        if(balance>1 && getBalance(root->left)<0){
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance<-1 && getBalance(root->right)<=0)
        return leftRotate(root);
        if(balance<-1 && getBalance(root->right)>0){
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
        
    }
    
    
    
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        if(k==1)
        return arr;
        vector<int>ans;
        Node* root=NULL;
        int c=0,l=0;
        for(int i=0;i<n;i++){
            c++;
            root=insertNode(root,arr[i]);
            if(c>k){
                root=deleteNode(root,arr[l++]);
                c--;
            }
            if(c==k)
                ans.push_back(maxValue(root));
        }
        return ans;
        
    }
};
