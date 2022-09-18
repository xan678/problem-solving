#include<iostream>
#include<string>
#include<vector>

using namespace std;

int firstMissingPositive(vector<int> &A){
    int i = 0;

    while(i<A.size()){
        if(A[i]<1 || A[i]> A.size() || A[i] == i+1 || A[i] == A[A[i] -1]){
            i++;
            continue;
        }
        int temp = A[i];
        A[i] = A[temp-1];
        A[temp-1] = temp;
    }

    for(int i = 0; i<A.size(); i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
    return A.size()+1;
}

int main()
{
    
    vector<int> A = {2,3,1,2};
    cout<<firstMissingPositive(A)<<endl;

    return 0;
}