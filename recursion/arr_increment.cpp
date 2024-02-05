void arr_increment(int arr[],int len){
    if(len<0)
        return;
    arr[len-1]+=len-1;
    arr_increment(arr,len-1);
}