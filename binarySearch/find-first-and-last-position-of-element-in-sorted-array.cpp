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