int Power(int val,int P){
    if(P==0)
        return 1;
    if(P==1)
        return val;
    return val*Power(val,P-1);
}