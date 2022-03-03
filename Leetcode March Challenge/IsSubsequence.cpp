#include<iostream>
#include <vector>
#include <string>
using namespace std;

bool isSorted(vector<int> something){
    for(int i = 0; i< something.size()-1; i++){
        if(something[i] > something[i+1]){
            return false;
        }
    }
    return true;
}

bool isSubsequence(string s, string t) {
    if(s.size() == 0) {
        return true;
    }
    vector<int> something;
    for(auto x : s){
        if(t.find(x) == -1){
            return false;
        }
        something.push_back(t.find(x));
        t.erase
    }
    return isSorted(something);
}

bool isSubsequence(string s, string t){
    
    vector<int> something
}

int main(){
    
    string t  = "ahbgdc";
    string s = "axc";
    cout<<isSubsequence(s,t)<<endl;

    return 0;
}