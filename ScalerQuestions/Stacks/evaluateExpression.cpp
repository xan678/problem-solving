#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

static vector<string> v;
static string top ;
static int s;

void push(string ch){
    v.push_back(ch);
    top = ch;
    s++;
}

string pop(){
    v.pop_back();
    top = v[v.size()-1];
    s--;
    return v[v.size()-1];
}

int evalRPN2(){
    if(s <= 0) return 0;

    if( top[0] != '/' && top[0] != '*'&& top[0] != '+' && top[0] != '-') {
        string p = top;
        pop();
        return stoi(p);
    }

    if(top.size() > 1 && top[0] == '-'){
        string p = top;
        pop();
        return stoi(p);
    }
    string op = top;
    pop();
    int left = evalRPN2();
    int right = evalRPN2();
    if(op[0] == '*'){
        return left * right;
    }
    if(op[0] == '/'){
        return right/left;        
    }
    if(op[0] == '+'){
        return left + right;
    }
    return right - left;
}

int evalRPN(vector<string> A){
    top = "";
    s = 0;
    for(auto x : A){
        push(x);
    }

    return evalRPN2();
}

int main()
{
    vector<string> A = { "-500", "-10", "/" };
    cout<<evalRPN(A)<<endl;
    return 0;
}