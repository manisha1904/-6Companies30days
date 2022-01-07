int *findTwoElement(int *arr, int n) {
        // code here
        int* ans=new int[2];
        int x=0;
        for(int i=0;i<n;i++){
            x^=(i+1);
            x^=(arr[i]);
        }
        int pos=-1;
        for(int i=0;i<32;i++){
            if(x&(1<<i)){
                pos=(1<<i);
                break;
            }
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(arr[i]&pos)
                a^=arr[i];
            else
                b^=arr[i];
            if((i+1)&pos)
                a^=(i+1);
            else
                b^=(i+1);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==a){
                ans[0]=a;
                ans[1]=b;
                break;
            }
            if(arr[i]==b){
                ans[0]=b;
                ans[1]=a;
                break;
            }
        }
        return ans;
        
    }
