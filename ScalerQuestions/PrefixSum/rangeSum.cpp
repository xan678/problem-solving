#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<long long> rangeSum(vector<int> &A, vector<vector<int>> &B){
    vector<long long> result;
    vector<int> prefixSum(A.size());

    prefixSum[0] = A[0];
    for(int i =1; i<A.size(); i++){
        prefixSum[i] = prefixSum[i-1] + A[i];
    }

    for(auto x : prefixSum){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x : B){
        if(x[0] == 1){
            result.push_back(prefixSum[x[1]-1]);
        }else{
            result.push_back(prefixSum[x[1]-1] - prefixSum[x[0]-2] );
        }
    }

    for(auto x : result){
        cout<<x<<" ";
    }
    return result;
}

int main(){
    vector<int> A = {7,3,1,5,5,5,1,2,4,5};

    vector<vector<int>> B = {
        {7,10},
        {3,10},
        {3,5},
        {1,10}
    };
    
    rangeSum(A,B);

    return 0;
}