#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> solve(int A, vector<vector<int>> &B){
    vector<int> result(A, 0);

    for(auto x : B){
        result[x[0]-1] += x[2];
        if(x[1] <= result.size()-1){
            result[x[1]] -= x[2];
        }
    }

    for(int i = 1; i<result.size();i++){
        result[i] += result[i-1];
    }
    return result;
}

int main()
{   
    vector<vector<int>> B = {
        {1,3,10},
        {6,9,2},
        {3,5,3},
        {2,8,4},
        {6,7,5}
    };
    int A = 10;
    vector<int> result = solve(A,B);

    for(auto x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}