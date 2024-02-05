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