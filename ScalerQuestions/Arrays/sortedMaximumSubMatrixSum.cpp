#include<iostream>
#include<string>
#include<vector>

using namespace std;

long solve(vector<vector<int>> &A){
    vector<vector<long>> pSum(A.size(), vector<long>(A[0].size(),0));
    for(int i = 0; i<A.size();i++){
        pSum[i][0] = A[i][0];
        for(int j = 1; j<A[0].size();j++){
            pSum[i][j] = pSum[i][j-1] + A[i][j];
        }
    }

    for(int j = 0; j<pSum[0].size();j++){
        for(int i = 1; i<pSum.size();i++){
            pSum[i][j] += pSum[i-1][j];
        }
    }

    long result = LONG_MIN;

    for(int i =0; i<A.size(); i++){
        for(int j = 0; j<A[0].size();j++){
            long sum = pSum[A.size()-1][A[0].size()-1];
            if(i>0){
                sum -= pSum[i-1][A[0].size()-1];
            }   
            if(j>0){
                sum -= pSum[A.size()-1][j-1];
            }
            if(i>0 && j>0){
                sum += pSum[i-1][j-1];
            }

            result = max(result,sum);
            
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> A = {
        {-5, -4, -3},
        {-1, 2, 3},
        {2, 2, 4}
    };

    cout<<solve(A)<<endl;   
    return 0;
}