#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
//#include "stack.h"

using namespace std;

static vector<int> v;
static int top = 0;
static int size = 0;

void push(int ch){
    v.push_back(ch);
    top = ch;
    size++;
}

int pop(){
    v.pop_back();
    top = v[v.size()-1];
    size--;
    return v[v.size()-1];
}

int solve(string A){
    for(auto x : A){
        //cout<<top<<" "<<((int)x)<<endl;
        if(x - top == 1){
            int t = pop();
            //cout<<"popped "<<((char)t)<<" size "<<size<<endl;
        }else{
            push((int)x);
            //cout<<"pushed "<<x<<" size "<<size<<endl;
        }
    }
    if(size != 0) return 0;
    return 1;
}

int main()
{
    string str = "(())";
    cout<<solve(str);   
    return 0;
}