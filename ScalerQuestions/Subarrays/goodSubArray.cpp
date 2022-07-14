#include<iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A, int B){
    int count;
    for(int i= 0; i<A.size(); i++){
        int sum = 0;
        for(int j = i; j<A.size();i++){
            sum = sum+A[j];
            if((j-i+1)%2 == 0 and sum <B) count++;
            if((j-i+1)%2 != 0 and sum > B)count ++;
        }
    }

    return count;
}

int main(){
    
    return 0;
}