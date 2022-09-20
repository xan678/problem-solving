#include<iostream>
#include<string>
#include<vector>

using namespace std;

int searchInsert(vector<int> &A, int B){
    int start = 0;
    int end = A.size()-1;
    int mid;
    while (start <= end)
    {
        mid = (start + end)/2;

        if(A[mid] == B){
            return mid;
        }
        
        if(A[mid] > B){
            end = mid -1;
        }
        else if (A[mid] < B ){
            start = mid + 1;
        }
    }
    
    if(A[mid] > B){
        return mid;
    }else{
        return mid+1;
    }
}

int main()
{
    vector<int> A = {1, 3, 7, 11, 18, 24};
    int B = 10;
    cout<<searchInsert(A,B)<<endl;
    return 0;
}