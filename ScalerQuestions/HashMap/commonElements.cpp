#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B){
    unordered_map<int,int> map;

    for(auto x : B){
        if(map.find(x) != map.end()){
            map[x]++; 
        }else{
            map.insert(make_pair(x,1));
        }
    }

    vector<int> result;

    for(auto x : A){
        if(map.find(x) != map.end() ){
            if(map[x] >0 ){
                result.push_back(x);
                map[x]--;
            }
        }
    }

    return result;
}

int main()
{   
    vector<int> A = {1, 2, 2, 1};
    vector<int> B = {2, 3, 1, 2};
    
    vector<int> result = solve(A, B);
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}