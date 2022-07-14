#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A, vector<vector<int>> &B){
    vector<vector<int>> result(A.size());

    for(int i = 0; i<A.size(); i++){
        result[i] = vector<int>(A[i].size());
        for(int j = 0; j<A[i].size();j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int main(){
    
    return 0;
}