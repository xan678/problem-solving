#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

static vector<int> v;
static int top ;
static int s;

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

string solve(string A){
    s = 0;
    top = 0;

    for(auto x : A){
        if(top == ((int) x)){
            pop();
        }else{
            push(x);
        }
    }
    string result = "";
    while (s > 0)
    {
        result.push_back(top);
        pop();
    }
    return string(result.rbegin(), result.rend());
}

int main()
{
    string p = "cddfeffe";
    cout<<solve(p);
    return 0;
}