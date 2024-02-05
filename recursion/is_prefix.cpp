bool is_prefix(string origin,string prefix,int strtpos){
    //if(strtpos==prefix.length())
    //    return true;
    return (strtpos==prefix.length()) or (origin[strtpos] == prefix[strtpos] and is_prefix(origin,prefix,strtpos+1));
}