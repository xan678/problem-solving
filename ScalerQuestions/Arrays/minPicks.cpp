#include<iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A){
    
    int maxE = INT_MIN;
    int minE = INT_MAX;

    for(int i = 0; i< A.size(); i++){
        if(A[i]%2 != 0){
            minE = min(minE,A[i]);
        }
        if(A[i]%2 == 0){
            
            maxE = max(maxE,A[i]);
        }
    }
    cout<<maxE<<" - "<<minE<<" = ";

    return maxE-minE;
}

int main(){
    vector<int> A = {0, 2, 9};
    cout<<solve(A)<<endl;
    return 0;
}