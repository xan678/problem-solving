#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int solve(int A, string B){
    unordered_map<char, int> map;
    for(auto x : B){
        if(map.find(x) != map.end()){
            map[x]++;
        }else{
            map.insert(make_pair(x,1));
        }
    }

    for(auto x : map){
        if(x.second != A){
            return -1;
        }
    }

    return 1;
}

int main()
{
    string B = "bcbcad";
    int A = 3;

    cout<<solve(A,B)<<endl;
    return 0;
}