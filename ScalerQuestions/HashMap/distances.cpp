#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int solve(vector<int> &A){
    unordered_map<int,vector<int>> map;

    for(int i = 0; i<A.size(); i++){
        int x = A[i];
        if(map.find(x) != map.end()){
            map[x].push_back(i);
        }else{
            vector<int> temp;
            temp.push_back(i);
            map.insert(make_pair(x,temp));
        }
    }
    int result = INT_MAX;
    for(auto x : map){
        if(x.second.size() <2){
            continue;
        }
        int ans = abs(x.second[0] - x.second[1]);
        result = min(result,ans);
    }
    
    return result == INT_MAX ? -1 : result;
}

int main()
{
    
    return 0;
}