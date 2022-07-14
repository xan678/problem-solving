#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solve(vector<vector<int>> &A){
    vector<int> result(A[0].size());

    for(int i = 0; i< A.size(); i++){
        for(int j = 0; j<A[i].size();j++){
            result[j] += A[i][j];
        }
    }

    return result;
}

int main(){
    
    return 0;
}