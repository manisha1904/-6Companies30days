bool isSafe(int x,int y,int n,int m){
    return (x>=0 && y>=0 && x<n && y<m);
}
bool solve(vector<vector<char>>&board,int r,int c,int n,int m,int k,string word){
    if(k==word.length())
    return true;
    if(!isSafe(r,c,n,m) || board[r][c]!=word[k])
    return false;
    board[r][c]='#';
    bool ans=solve(board,r-1,c,n,m,k+1,word)||
                solve(board,r+1,c,n,m,k+1,word)||
                solve(board,r,c-1,n,m,k+1,word)||
                solve(board,r,c+1,n,m,k+1,word);
                board[r][c]=word[k];
                return ans;
}
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(board,i,j,n,m,0,word)){
                    return true;
                    
                }
                
            }
        }
        return false;
        
    }
