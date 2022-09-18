#include<iostream>
#include<string>
#include<vector>

using namespace std;

int floorElement(vector<int> &A, int B){
    int ans = INT_MIN;
    int start =0;
    int end = A.size()-1;

    while(start<=end){
        int mid = (start + end)/2;

        if(A[mid] > B){
            end = mid-1;
        }
        if(A[mid]<=B){
            ans = max(ans, A[mid]);
            start = mid+1;
        }
    }

    return ans;
}

int main()
{
    vector<int> A = {-5, 2, 3, 6, 9, 10, 11, 14, 18};
    int B = 5;
    cout<<floorElement(A,B);

    return 0;
}