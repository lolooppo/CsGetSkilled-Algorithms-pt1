//https://leetcode.com/problems/valid-triangle-number/description/
int triangleNumber(vector<int>& v) {
    int res = 0 , n = v.size();
    if(n<3)
        return 0;
    sort(v.begin(),v.end());
    for(int i = 0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            int pos = lower_bound(v.begin(),v.end(),v[i]+v[j]) - v.begin();
            if(pos>j)
                res+=(pos-j-1);
        }
    }
    return res;
}