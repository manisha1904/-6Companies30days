void rotate(int n,int a[][n])
{
    //code here
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp=a[i][n-j-1];
            a[i][n-j-1]=a[n-j-1][n-i-1];
            a[n-j-1][n-i-1]=a[n-i-1][j];
            a[n-i-1][j]=a[j][i];
            a[j][i]=temp;
        }
    }
}
