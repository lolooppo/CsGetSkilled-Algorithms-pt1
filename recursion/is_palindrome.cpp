bool is_palindrome(int arr[],int len){
    if(len==1)
        return true;
    return arr[0]==arr[len-1] and is_palindrome(arr+1,len-2);
}