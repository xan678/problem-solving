#include<iostream>
#include<string>
#include<vector>

using namespace std;

// int solve( vector<vector<int>> &A, int B){

//     int i  = 0;
//     int j = A[0].size()-1;

//     int result = INT_MAX;

//     while(i<A.size() && j<A[0].size()){
//         if(A[i][j] > B ){
//             j--;
//         }
//         else if(A[i][j] < B){
//             i++;
//         }
//         else {
//             //cout<<"I am here"<<endl;
//             cout<<i<<" "<<j<<endl;
//             int value = (i+1)*1009 + (j+1);
//             result = min(result, value);
//             j--;
//         }
//         //cout<<i<<" "<<j<<endl;
//     }

//     return result;
// }

int solve(vector<vector<int>> &A, int B){
    int result = INT_MAX;
    for(int i = 0; i<A.size();i++){
        for(int j = 0;j<A[0].size();j++){
            if(A[i][j] == B){
                result = min(result, ((i+1)*1009 + (j+1)));
            }
        }
    }

    return result == INT_MAX ? -1 : result;
}

int main()
{
    vector<vector<int>> A = {
        {2,8,8,8},
        {2,8,8,8},
        {2,8,8,8}
    };
    cout<<solve(A,8);
    return 0;
}