//selection sort
void selection_sort(vector<int>& v){
    for(int i = 0;i<(int)v.size()-1;i++){
        int idx = i;
        for(int j = i+1;j<(int)v.size();j++){
            if(v[j]<v[idx])
                idx = j;
        }
        swap(v[idx],v[i]);
    }
}