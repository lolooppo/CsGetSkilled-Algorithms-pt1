int arr_sum(int arr[],int len){
    if(len==1)
        return arr[len-1];
    return arr[len-1]+arr_sum(arr,len-1);
}