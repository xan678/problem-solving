    int num  = 0;
    int mul = 1;
    int i = 0;
    while(i<A.size()){
        num += mul*(A.at(A.size()-i-1) - '0');
        mul = mul*10;
        i++;
    }
    return num%B;