        for(auto x : A){
        //cout<<top<<" "<<((int)x)<<endl;
        if(x - top == 1 || x - top == 2){
            int t = pop();
            //cout<<"popped "<<((char)t)<<" size "<<size<<endl;
        }else{
            push((int)x);
            //cout<<"pushed "<<x<<" size "<<size<<endl;
        }
    }
    if(s != 0) return 0;
    return 1;