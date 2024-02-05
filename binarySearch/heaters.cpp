//https://leetcode.com/problems/heaters/description
bool is(vector<int>& ho, vector<int>& he,int m){
    int j = 0;
    for(int i = 0;i<he.size();i++){
        int left = he[i]-m , right = he[i]+m;
        while(j<ho.size() and ho[j]>=left and ho[j]<=right){
            j++;
        }
    }
    return j==ho.size();
}
int findRadius(vector<int>& ho, vector<int>& he) {
    sort(he.begin(),he.end());
    sort(ho.begin(),ho.end());
    int l = 0 , r = 1e9,res = 0;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(is(ho,he,mid)){
            r = mid-1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    return res;
}