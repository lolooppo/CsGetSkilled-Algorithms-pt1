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