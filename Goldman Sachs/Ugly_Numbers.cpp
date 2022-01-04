	ull getNthUglyNo(int n) {
	    // code here
	    set<ull>s;
	    s.insert(1);
	    int i=1;
	    while(i<n){
	       auto x=s.begin();
	       ull temp=*x;
	       s.erase(x);
	        s.insert(temp*2);
	        s.insert(temp*3);
	        s.insert(temp*5);
	        
	        i++;
	    }
	    return *s.begin();
	    
	}
