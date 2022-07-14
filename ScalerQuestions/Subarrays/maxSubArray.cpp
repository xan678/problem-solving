#include<iostream>
#include <vector>
#include <string>
using namespace std;

//carry forward :- tle
int solve(int A, vector<int> &C, int B){
    int maxSum = INT_MIN;

    for(int i = 0; i< A; i++){
        int sum = 0;
        for(int j = i; j<A; j++){
            sum = sum+ C[i];
            cout<<"Sum of subarray ("<<i<<","<<j<<")"<<sum<<endl;
            if(sum <= B){
                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
}

// int solve(vector<int> &A){
    
// }

int main(){
    int A = 9;
    int B = 78;
    vector<int> C = {7, 1, 8, 5, 8, 5, 3, 3, 5 };
    cout<<solve(A,C,B)<<endl;
    return 0;
}