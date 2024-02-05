double arr_average(int arr[],int len){
   if(len==1)
        return (double)arr[0];
   return ((double)arr[len-1]+(arr_average(arr,len-1)*(len-1)))/len;
}