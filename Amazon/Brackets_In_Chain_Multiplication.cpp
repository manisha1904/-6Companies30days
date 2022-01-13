int dp[102][102];
int bracket[102][102];
string ans="";
void parenthesis(int i,int j,char& ch){
    if(i==j){
        ans.push_back(ch++);
        return;
    }
    ans.push_back('(');
    parenthesis(i,bracket[i][j],ch);
    parenthesis(bracket[i][j]+1,j,ch);
    ans.push_back(')');
}
int solve(int arr[],int i,int j){
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        int count=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        
        if(count<dp[i][j]){
        dp[i][j]=min(dp[i][j],count);
        bracket[i][j]=k;
        }
    }
    return dp[i][j];
}
    string matrixChainOrder(int p[], int n){
        // code here
        memset(dp,-1,sizeof(dp));
        memset(bracket,-1,sizeof(bracket));
        solve(p,1,n-1);
        char ch='A';
        parenthesis(1,n-1,ch);
        return ans;
    }
