#include<iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A){
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    for(auto x: A){
        minNum = min(x,minNum);
        maxNum = max(x,maxNum);
    }
    int minIndex = -1;
    int maxIndex = -1;
    int result = A.size();
    for(int i = A.size()-1; i>=0;i++){
        if(A[i] == maxNum){
            maxIndex = i;
        }
        if(A[i] == minNum){
            minIndex = i;
        }
        if(minIndex >-1 and maxIndex >-1){
            result = min(result, abs(maxIndex -minIndex) +1);
        }
    }

    return result;
}
int main(){
    return 0;
}