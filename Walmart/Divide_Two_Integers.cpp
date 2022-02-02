 int divide(int dividend, int divisor) {
        if(dividend==0)
            return 0;
        if(dividend==INT_MAX){
            if(divisor==1)
                return dividend;
            else if(divisor==-1)
                return INT_MIN;
        }
        if(dividend==INT_MIN){
            if(divisor==1)
                return dividend;
            else if(divisor==-1)
                return INT_MAX;
        }
        bool sign=(dividend>0 ^ divisor>0);
        int ans=0;
        dividend=abs(dividend);
        long div=abs(divisor);
        while(dividend>=div){
            int temp=1;
            while(dividend>(div<<1)){
                div=div<<1;
                temp=temp<<1;
            }
            ans+=temp;
            dividend=dividend-div;
            div=abs(divisor);
        }
        return sign?(-1)*ans:ans;
        
    }
