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