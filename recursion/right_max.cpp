void right_max(int arr[],int len,int sz){
    if(!len)
        return;
    if(len!=sz){
        arr[len-1] = max(arr[len-1],arr[len]);
    }
    right_max(arr,len-1,sz);
}