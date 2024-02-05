//count sort for strings based on the first two characters
const int letters = 26;
int id(string& str){
    int f = str[0]-'a',s = str[1]-'a';
    return f * letters + s;
}
void _count_sort(vector<string>& v){
    int round = letters * letters;
    vector<vector<string>>cnt(letters*letters);
    for(int i = 0;i<(int)v.size();i++){
        cnt[id(v[i])].push_back(v[i]);
    }
    int idx = 0;
    for(int i = 0;i<round;i++){
        for(int j = 0;j<(int)cnt[i].size();j++,idx++){
            v[idx] = cnt[i][j];
        }
    }
}