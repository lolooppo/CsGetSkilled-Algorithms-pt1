//count sort for strings based on the first character
void count_sort(vector<string>& v){
    int n = 26,idx = 0;
    vector<vector<string>>cnt(n+1);
    for(int i = 0;i<(int)v.size();i++){
        cnt[v[i][0]-'a'].push_back(v[i]);
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<(int)cnt[i].size();j++,idx++){
            v[idx] = cnt[i][j];
        }
    }
}