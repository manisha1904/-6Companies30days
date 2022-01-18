int LIS(vector<int>v){
      if(v.size()==0)
      return 0;
      vector<int>temp(v.size(),0);
      temp[0]=v[0];
      int len=1;
      for(int i=1;i<v.size();i++){
          auto start=temp.begin();
          auto end=temp.begin()+len;
          auto it=lower_bound(start,end,v[i]);
          if(it==temp.begin()+len)
          temp[len++]=v[i];
          else
          *it=v[i];
      }
     return len;
  }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        map<int,int>m;
        for(int i=0;i<M;i++)
        m.insert({B[i],i});
        vector<int>v;
        for(int i=0;i<N;i++){
            if(m.find(A[i])!=m.end())
            v.push_back(m[A[i]]);
        }
        int temp=LIS(v);
        int ans=(N-temp)+(M-temp);
        return ans;
        
    }
