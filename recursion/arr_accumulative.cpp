void arr_accumulative(int arr[],int len){
    if(len==1)
        return;
    arr_accumulative(arr,len-1);
    arr[len-1]+=arr[len-2];
}