#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(vector<int> &A, int B){
    int i = 0;
    int j = A.size()-1;
    int resultCount = 0;

    int mod = 1000000007;

    while( i< j){

        if(A[i] == A[j] ){
            if(2* A[i] == B){
                int n = j-i + 1;
                int s = (((n*(n-1))/2)%mod);
                resultCount = (resultCount + s) % mod;
                break;
            }
        }else{
            int sum = A[i] + A[j];
            if(sum < B){
                i++;
            }else if (sum > B){
                j--;
            }else if (sum == B){
                int counti = 1;
                int countj = 1;

                while(A[i] == A[i+1]){
                    counti++;
                    i++;
                }
                while(A[j] == A[j-1]){
                    countj++;
                    j--;
                }
                
                resultCount = (resultCount + (counti*countj)%mod) %mod;
                i++;
                j--;
            }
        }
    }

    return resultCount%mod ;
}

int main()
{
    //vector<int> A = {1,3,4,4,5,5,5,5,6,6,6,7,10};
    vector<int> A = {1, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    //int B = 10;
    int B = 2;
    cout<<solve(A,B);   
    return 0;
}   