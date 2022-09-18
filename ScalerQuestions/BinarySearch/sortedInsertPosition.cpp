#include<iostream>
#include<string>
#include<vector>

using namespace std;

int searchInsert(vector<int> &A, int B){
    int start = 0; 
    int end = A.size()-1;
    int mid = INT_MIN;
    while(start <= end){
        mid = (start+end)/2;
        if(A[mid] == B){
            return mid;
        }
        if(A[mid]> B){

        }
        if(A[mid] < B){
            
        }
    }
}

int main()
{
    
    return 0;
}