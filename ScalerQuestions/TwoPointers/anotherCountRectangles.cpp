#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(vector<int> &A, int B){
    int mod = (1000*1000*1000)+7;
    int startIndex = 0;
    int endIndex = A.size()-1;
    long count = 0;
    long element = (long)B;
    while(startIndex<= endIndex){
        long mul = (long)(A[startIndex] * A[endIndex]);
        if(mul < element){
            int size = endIndex - startIndex +1;
            count = count%mod + (((long)2*size)-1)%mod;
            startIndex++;
        }
        else{
            endIndex--;
        }
    }

    return (int)(count%mod);
}

int main()
{
    vector<int> A = {1,2,3,4,5};
    int B = 7;

    cout<<solve(A,B)<<endl;
    return 0;
}