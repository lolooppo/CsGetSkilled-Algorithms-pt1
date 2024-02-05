//insertion sort without shifting
void _insertion_sort(vector<int>& v){
    for(int i = 1;i<(int)v.size();i++){
        int pos = i;
        for(int j = i-1;j>=0 and v[j]>v[pos];j--,pos--)
            swap(v[j],v[pos]);
    }
}