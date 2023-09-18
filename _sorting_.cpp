#include <bits/stdc++.h>

using namespace std;
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
//insertion sort without shifting
void _insertion_sort(vector<int>& v){
    for(int i = 1;i<(int)v.size();i++){
        int pos = i;
        for(int j = i-1;j>=0 and v[j]>v[pos];j--,pos--)
            swap(v[j],v[pos]);
    }
}
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

int main(){
    vector<string>v = {"axz","axa","zzz","abc","abe"};
    _count_sort(v);
    for(auto& x:v)cout<<x<<" ";

}
