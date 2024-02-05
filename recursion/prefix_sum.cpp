int prefix_sum(int arr[],int len,int key){
    if(key==0)
        return 0;
    return arr[0] + prefix_sum(arr+1,len-1,key-1);
}