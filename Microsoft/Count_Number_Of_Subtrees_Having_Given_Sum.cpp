int solve(Node* root,int& count,int x){
    if(!root)
    return 0;
    int l=solve(root->left,count,x);
    int r=solve(root->right,count,x);
    int sum=l+r+root->data;
    
    if(sum==x)
    count++;
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	if(!root)
	return 0;
	int count=0;
	int l=solve(root->left,count,X);
	int r=solve(root->right,count,X);
	if((l+r+root->data)==X)
	count++;
	return count;
}
