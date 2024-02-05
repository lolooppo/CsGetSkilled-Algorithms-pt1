void right_max2(int arr[],int len){
    if(len==1)
        return ;
    right_max2(arr+1,len-1);
    arr[0] = max(arr[0],arr[1]);
}