#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(vector<vector<int>> & A){
    int totalSum = 0;
    for(int i = 0; i<A.size();i++){
        for(int j = 0; j< A[0].size(); j++){
            totalSum += (A[i][j] *(i+1)*(j+1)*(A.size()-i)*(A[0].size()-j));
        }
    }

    return totalSum;
}

int main()
{
    
    return 0;
}