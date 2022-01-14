vector<int>v;
    stack<int>s;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int count;
        
        while(!s.empty() && v[s.top()]<=price){
            s.pop();
        }
        count=(s.empty()?i+1:i-s.top());
        s.push(i++);
        
        return count;
        
    }
