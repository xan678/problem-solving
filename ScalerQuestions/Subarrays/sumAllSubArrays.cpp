#include<iostream>
#include <vector>
#include <string>
using namespace std;


//Gives TLE -> Brute force prefix sum
long solve(vector<int> &A){
    vector<int> prefixSum(A.size());

    prefixSum[0] = A[0];
    for(int i = 1; i<A.size(); i++){
        prefixSum[i] = A[i] + prefixSum[i-1];
    }
    long sum = 0;
    for(int s = 0; s<prefixSum.size(); s++){
        for(int e =s; e<prefixSum.size(); e++){
            if(s == 0){
                sum += prefixSum[e];
            }
            else{
                sum+= prefixSum[e] - prefixSum[s-1];
            }
        }
    }

    return sum;
}

long solve(vector<int> &A){

    int s = 1;
    int e = A.size();

    long sum = 0;
    for(int i = 0; i<A.size(); i++){
        int f = (i+1)*(e-i+1);
        sum = sum + A[i]*f; 
    }

    return sum;
}


int main(){
    
    return 0;
}