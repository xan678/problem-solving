#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

static vector<int> v;
static int top = 0;
static int s = 0;

void push(int ch){
    v.push_back(ch);
    top = ch;
    s++;
}

int pop(){
    v.pop_back();
    top = v[v.size()-1];
    s--;
    return v[v.size()-1];
}

int solve(string A){
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
}

int main()
{
    string str = "()[]";
    cout<<solve(str);  
    return 0;
}