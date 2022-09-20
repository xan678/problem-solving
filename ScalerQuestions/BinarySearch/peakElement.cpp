#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int solve(vector<int> &A){
    if(A[0] > A[1]){
        return A[0];
    }
    if(A[A.size()-1] > A[A.size()-2]){
        return A[A.size()-1];
    }

    int start = 1;
    int end = A.size()-2;

    while(start <= end){
        int mid = (start + end) /2;

        if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){
            return A[mid];
        }
        else if(A[mid] >A[mid -1] && A[mid ]< A[mid+1]){
            start = mid + 1;
        }else {
            end = mid -1;
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {5, 17, 100, 11} ;
    cout<<solve(A)<<endl;  
    return 0;
}