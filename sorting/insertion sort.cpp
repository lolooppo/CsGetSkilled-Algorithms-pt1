//insertion sort
void insertion_sort(vector<int>& v){
    for(int i = 1; i < (int)v.size() ; i++){
        int key = v[i], j = i-1;
        while(j>=0 and v[j]>key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}