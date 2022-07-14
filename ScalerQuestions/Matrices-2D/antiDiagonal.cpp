#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A){
    vector<vector<int>> result;

    //solve for the top row
    for(int m = 0; m<A.size();m++){
        vector<int> res;
        int i = 0;
        int j = m;
        while(i<=m and j>=0){
            res.push_back(A[i][j]);
            i++;
            j--;
        }
        for(int z = m+1; z<A.size();z++){
            res.push_back(0);
        }
        result.push_back(res);
    }

    for(int n = 1;n<A.size(); n++){
        vector<int> res;
        int i = n;
        int j = A.size()-1;
        while(i<A.size() and j>=n){
            res.push_back(A[i][j]);
            i++;
            j--;
        }
        for(int z = 0; z<n;z++){
            res.push_back(0);
        }
        result.push_back(res);
    }
    return result;
}

int main(){
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> result = solve(A);
    return 0;
}