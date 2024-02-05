//https://leetcode.com/problems/most-profit-assigning-work/submissions/1051741534/
int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w){
    vector<pair<int,int>>vp;
    for(int i =0 ;i<(int)d.size();i++){
        vp.push_back(make_pair(d[i],p[i]));
    }
    sort(d.begin(),d.end()),sort(vp.begin(),vp.end());
    int res = 0;
    for(int i = 1;i<(int)vp.size();i++){
        vp[i].second = max(vp[i].second,vp[i-1].second);
    }
    for(int i = 0;i<(int)w.size();i++){
        int idx = upper_bound(d.begin(),d.end(),w[i]) - d.begin();
        if(idx){
            idx--;
            res+=vp[idx].second;
        }
    }
    return res;
}
