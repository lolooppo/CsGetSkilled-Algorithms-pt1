int length_3n_Plus_1(int n){
    if(n==1)
        return 1;
    return 1 + (n%2?length_3n_Plus_1(3*n+1):length_3n_Plus_1(n/2));
}