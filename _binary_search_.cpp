//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
vector<int> searchRange(vector<int>& v, int target) {
    int l{-1},r{-1},left = 0,right = (int)v.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(v[mid]>=target){
            right = mid-1;
            l = mid;
        }
        else{
            left = mid+1;
        }
    }
    if(l!=-1 and v[l]!=target)l = -1;
    left = 0,right = (int)v.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(v[mid]<=target){
            left = mid+1;
            r = mid;
        }
        else{
            right = mid-1;
        }
    }
    if(r!=-1 and v[r]!=target)r = -1;
    return {l,r};
}

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
//https://leetcode.com/problems/arranging-coins/description/
int arrangeCoins(int n) {
    int l = 0 , r = 65536 , res;
    while(l<=r){
        long long m = l + (r-l)/2;
        if((long long)m*(m+1)/2<=n)res = m,l = m+1;
        else r = m-1;
    }
    return res;
}
//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
bool is(vector<int>&v ,int target ,int divisor){
    int n = v.size() , sum{0};
    for(int i = 0;i<n;i++){
        int x = (v[i] + divisor - 1) / divisor;
        sum+=x;
    }
    return sum<=target;

}
int smallestDivisor(vector<int>& nums, int threshold) {
    int res = -1,l = 1 , r = 1000000;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(is(nums,threshold,mid)){
            r = mid - 1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    return res;
}
//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
bool is(vector<int>&b,int &m,int& k,int& num){
    int cnt = 0,res = 0,n = b.size();
    for(int i = 0;i<n;i++){
        int x = b[i] - num;
        if(x<=0)cnt++;else { cnt/=k;res+=cnt,cnt = 0;}//count the conseqative valid days
    }
    cnt/=k;
    res+=cnt;
    return res>=m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int l = 1 , r = 1000000000 , res = -1;
    if(((int)bloomDay.size()/k)<m)return res;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(is(bloomDay,m,k,mid)){
            r = mid-1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    return res;
}
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
//https://leetcode.com/problems/find-peak-element/description/
int findPeakElement(vector<int>& nums) {
    int l = 0,r = nums.size()-1,ans = -1;
    if(nums.size()==1)return 0;
    while(l<r){
        int mid = (l + r + 1)/2;
        if(mid == 0 or nums[mid]>nums[mid-1])
           l = mid;
        else
            r = mid-1;
    }
    return l;
}
