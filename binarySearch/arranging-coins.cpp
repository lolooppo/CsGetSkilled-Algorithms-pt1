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
