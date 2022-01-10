int isValid(vector<vector<int>> mat){
        // code here
        int N=mat.size();
        bool check[N+1];
        for(int i=0;i<N-2;i+=3){
            for(int j=0;j<N-2;j+=3){
                memset(check,false,sizeof(check));
                for(int m=i;m<i+3;m++){
                    for(int n=j;n<j+3;n++){
                        if(mat[m][n]>9 || mat[m][n]<0 || check[mat[m][n]])
                        return 0;
                        if(mat[m][n]!=0)
                        check[mat[m][n]]=true;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            memset(check,false,sizeof(check));
            for(int j=0;j<N;j++){
                if(mat[i][j]>9 || mat[i][j]<0 || check[mat[i][j]])
                return 0;
                if(mat[i][j]!=0)
                check[mat[i][j]]=true;
            }
        }
        for(int i=0;i<N;i++){
            memset(check,false,sizeof(check));
            for(int j=0;j<N;j++){
                if(mat[j][i]>9 || mat[i][j]<0 || check[mat[j][i]]){
                return 0;
                }
                if(mat[j][i]!=0)
                check[mat[j][i]]=true;
            }
        }
        return 1;
    }
