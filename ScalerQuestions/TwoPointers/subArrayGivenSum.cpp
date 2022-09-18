#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> solve(vector<int> &A, int B){
vector<int> pfSum(A.size(), -1);
    pfSum[0] = A[0];
 
    for(int i = 1; i<A.size(); i++){
        pfSum[i] = pfSum[i-1] + A[i];
    }

    int startIndex = 0; 
    int endIndex = 0;
    while (endIndex<A.size())
    {   
        int subSum; 
        if(startIndex == 0){
            subSum = pfSum[endIndex];
        }
        else{
            subSum = pfSum[endIndex] - pfSum[startIndex-1];
        }

        if(subSum <B ){
            endIndex++;
        }
        if(subSum >B){
            startIndex++;
        }
        if(subSum == B){
            vector<int>result;
            for(int i = startIndex; i<=endIndex;i++){
                result.push_back(A[i]);
            }
            return result;
        }
    }

    return vector<int>(1,-1); 
}

int main()
{
    vector<int> A = {1, 10};
    int B = 10;

    vector<int> result = solve(A,B);
    for(auto x: result){
        cout<<x<<" ";
    }   
    return 0;
}