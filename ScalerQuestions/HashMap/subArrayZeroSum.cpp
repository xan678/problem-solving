#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int solve(vector<int> &A){
    unordered_map<int,int> map;
    map.insert(make_pair(A[0], 1));
    int prev = A[0];

    for(int i = 1; i<A.size();i++){
        int sum = prev + A[i];
        prev = sum;

        if(map.find(sum) != map.end()){
            return 1;
        }
        else{
            map.insert(make_pair(sum,1));
        }
    }
    return 0;
}

int main()
{
    
    return 0;
}