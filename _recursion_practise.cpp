int length_3n_Plus_1(int n){
    if(n==1)
        return 1;
    return 1 + (n%2?length_3n_Plus_1(3*n+1):length_3n_Plus_1(n/2));
}

int Power(int val,int P){
    if(P==0)
        return 1;
    if(P==1)
        return val;
    return val*Power(val,P-1);
}

int arr_maximum(int arr[],int len){
    if(len==1)
        return arr[0];
    return max(arr[len-1],arr_maximum(arr,len-1));
}

int arr_sum(int arr[],int len){
    if(len==1)
        return arr[len-1];
    return arr[len-1]+arr_sum(arr,len-1);
}

double arr_average(int arr[],int len){
   if(len==1)
        return (double)arr[0];
   return ((double)arr[len-1]+(arr_average(arr,len-1)*(len-1)))/len;
}

void arr_increment(int arr[],int len){
    if(len<0)
        return;
    arr[len-1]+=len-1;
    arr_increment(arr,len-1);
}

void arr_accumulative(int arr[],int len){
    if(len==1)
        return;
    arr_accumulative(arr,len-1);
    arr[len-1]+=arr[len-2];
}

void left_max(int arr[],int len){
    if(len==1)
        return;
    left_max(arr,len-1);
    arr[len-1] = max(arr[len-1],arr[len-2]);
}

void right_max(int arr[],int len,int sz){
    if(!len)
        return;
    if(len!=sz){
        arr[len-1] = max(arr[len-1],arr[len]);
    }
    right_max(arr,len-1,sz);
}

void right_max2(int arr[],int len){
    if(len==1)
        return ;
    right_max2(arr+1,len-1);
    arr[0] = max(arr[0],arr[1]);
}

int suffix_sum(int arr[],int len,int key){
    if(len<key)
        return 0;
    return arr[len-1]+suffix_sum(arr,len-1,key);
}

int prefix_sum(int arr[],int len,int key){
    if(key==0)
        return 0;
    return arr[0] + prefix_sum(arr+1,len-1,key-1);
}

bool is_palindrome(int arr[],int len){
    if(len==1)
        return true;
    return arr[0]==arr[len-1] and is_palindrome(arr+1,len-2);
}

bool is_prefix(string origin,string prefix,int strtpos){
    //if(strtpos==prefix.length())
    //    return true;
    return (strtpos==prefix.length()) or (origin[strtpos] == prefix[strtpos] and is_prefix(origin,prefix,strtpos+1));
}