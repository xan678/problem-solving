#include<iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A, int B){
    int count = 0;
    for(int i = 0; i<A.size(); i++){
        int sum = 0;
        for(int j = i; j<A.size(); j++){
            sum = sum + A[j];
            if(sum<B) count++;
        }
    }
    return count;
}

int main(){
    
    return 0;
}