int minSteps(int D){
        // code here
        int sum=0;
        int step=0;
        while(sum<D || (D-sum)%2!=0){
            step++;
            sum+=step;
        }
        return step;
    }
