#include<iostream>
#include<string>
#include<vector>

using namespace std;

int countFrequency(vector<int> &A, int B){
    
    int start = 0; 
    int end = A.size()-1;

    int firstOccurance = INT_MAX;
    while (start <= end)
    {   
        int mid = (start + end )/2;
        
        if(A[mid] < B){
            start = mid+1;
        }
        if(A[mid] > B){
            end = mid-1;
        }
        if(A[mid] == B){
            end = mid-1;
            firstOccurance = min(firstOccurance,mid);
        }
        
    }

    int lastOccurence = -1;
    start = 0;
    end = A.size()-1;
    while (start <= end)
    {   
        int mid = (start + end )/2;
        
        if(A[mid] < B){
            start = mid+1;
        }
        if(A[mid] > B){
            end = mid-1;
        }
        if(A[mid] == B){
            start = mid+1;
            lastOccurence = max(lastOccurence,mid);
        }
    }
    return lastOccurence -firstOccurance + 1;
    
}

int main()
{
    vector<int> A = {-5, -5, -3, 0, 0, 1 ,1 , 5,5,5,5,5,5,5, 8, 10, 10, 15, 15};
    int B = 5;
    cout<<countFrequency(A,B);
    return 0;
}