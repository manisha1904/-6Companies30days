vector<string> generate(int N)
{
	// Your code here
	vector<string>ans;
	ans.push_back("1");
	for(int i=2;i<=N;i++){
	    string temp="";
	    int x=i;
	    while(x){
	        temp+=(x%2 + '0');
	        x/=2;
	    }
	    reverse(temp.begin(),temp.end());
	    ans.push_back(temp);
	}
	return ans;
}
