#include<iostream>
#include<string>
#include<vector>

using namespace std;

int sovle(vector<int> &A, int B){
    int startIndex = 0;
    int endIndex = A.size()-1;

    int resultCount = 0;
    while(startIndex < endIndex){
        int sum = A[startIndex] + A[endIndex];
        if(sum < B){
            startIndex++;
        }
        if(sum > B){
            endIndex--;
        }
        if(sum == B){
            resultCount++;        
            startIndex++;
            endIndex--;    
        }
    }

    return resultCount;
}

int main()
{
    vector<int> A = {-3, 0, 1, 3, 6, 8, 11, 14, 18, 25};
    int B = 17;
    cout<<sovle(A,B)<<endl;
    return 0;
}