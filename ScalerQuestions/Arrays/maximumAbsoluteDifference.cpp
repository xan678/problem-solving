#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solution(vector<int> &A){
    int maxSum=INT_MIN;
    int maxDiff = INT_MIN;
    int minSum = INT_MAX;
    int minDiff = INT_MAX;

    for(int i = 0; i<A.size(); i++){
        int sum = A[i] + i;
        int diff = A[i] - i;

        maxSum = max(maxSum, sum);
        minSum = min (minSum, sum);

        maxDiff = max(maxDiff, diff);
        minDiff = min(minDiff, diff);
    }

    return max((maxSum - minSum),(maxDiff - minDiff));
}

int main()
{
    
    return 0;
}