#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A){
    vector<pair<int, int>> whereAreZeroes;

    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[i].size(); j++){
            if(A[i][j] == 0){
                whereAreZeroes.push_back(make_pair(i,j));
            }
        }
    }

    for(pair<int ,int> p : whereAreZeroes){
        for( int j = 0; j<A[p.first].size(); j++){
            A[p.first][j] = 0;
        }
        for(int i = 0; i<A.size(); i++){
            A[i][p.second] = 0;
        }
    }

    return A;
}

int main(){
    vector<vector<int>> A = {
        {1,2,3,4},
        {5,6,7,0},
        {9,2,0,4},
    };

    vector<vector<int>> result = solve(A);
    for(auto x: result){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}