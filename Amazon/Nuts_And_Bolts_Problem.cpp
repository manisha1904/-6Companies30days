int partition(char* nuts,int low,int high,char pivot){
    int i=low;
    for(int j=low;j<high;j++){
        if(nuts[j]<pivot){
            char temp=nuts[i];
            nuts[i]=nuts[j];
            nuts[j]=temp;
            i++;
        }
        else{
            if(nuts[j]==pivot){
                char temp=nuts[j];
                nuts[j]=nuts[high];
                nuts[high]=temp;
                j--;
            }
        }
    }
    char temp=nuts[i];
    nuts[i]=nuts[high];
    nuts[high]=temp;
    return i;
}
void quickSort(char* nuts,char* bolts,int low,int high){
    if(low<high){
        int pivot=partition(nuts,low,high,bolts[high]);
        partition(bolts,low,high,nuts[pivot]);
        quickSort(nuts,bolts,low,pivot-1);
        quickSort(nuts,bolts,pivot+1,high);
    }
}
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    quickSort(nuts,bolts,0,n-1);
	    
	}
