//count sort
void count_sort(vector<int>& v){
    int n = v.size(),mx{0},idx{0};
    mx = *max_element(v.begin(),v.end());

    vector<int>cnt(mx+1,0);
    for(int i = 0;i<n;i++){
        cnt[v[i]]++;
    }

    for(int i = 0;i<=mx;i++){
        for(int j = 0;j<cnt[i];j++,idx++)
            v[idx] = i;
    }
}