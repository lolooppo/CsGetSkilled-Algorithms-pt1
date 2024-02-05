int suffix_sum(int arr[],int len,int key){
    if(len<key)
        return 0;
    return arr[len-1]+suffix_sum(arr,len-1,key);
}