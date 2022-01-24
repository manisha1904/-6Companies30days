/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>&grid,int r,int r_end,int c,int c_end,int factor){
        int sum=0;
        for(int i=r;i<r_end;i++){
            for(int j=c;j<c_end;j++){
                sum+=grid[i][j];
            }
        }
        Node* ans;
        if(factor==1){
            ans=new Node(sum,true);
        }
        else if(sum==0)
            ans = new Node(false,true);
        else if(sum==factor*factor)
            ans = new Node(true,true);
        else{
             ans=new Node(true,false);
            factor=factor/2;
            ans->topLeft=solve(grid,r,r+factor,c,c+factor,factor);
            ans->topRight=solve(grid,r,r+factor,c+factor,c_end,factor);
            ans->bottomLeft=solve(grid,r+factor,r_end,c,c+factor,factor);
            ans->bottomRight=solve(grid,r+factor,r_end,c+factor,c_end,factor);
        }
        return ans;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        Node* ans= solve(grid,0,n,0,n,n);
        return ans;
        
    }
};
