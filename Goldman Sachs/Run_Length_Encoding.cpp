string encode(string src)
{     
  //Your code here 
  string ans="";
  for(int i=0;i<src.length();i++){
      int j=i;
      int count=1;
      while(src[++j]==src[i] && j<src.length()){
          count++;
      }
      
      ans+=src[i]+to_string(count);
      i=j-1;
  }
  return ans;
}     
