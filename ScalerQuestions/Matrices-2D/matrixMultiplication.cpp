#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A, vector<vector<int>> &B){
    int m = A.size();
    int p = B[0].size();
    int n = B.size();
    vector<vector<int>> result (m,vector<int>(p));

    for(int i = 0; i<m; i++){
        for(int j = 0; j<p; j++){
            int sum = 0;
            for(int k = 0; k<n;k++){
                 sum+= A[i][k]*B[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

int main(){
    vector<vector<int>> A = {
        {1,1},
    };
    vector<vector<int>> B = {
        {2},
        {3}
    };

    vector<vector<int>> result = solve(A,B);
    for(auto x:result){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}