#include<iostream>
#include<string>
#include<vector>

using namespace std;

void display(vector<vector<int>> &result){
    for(auto x : result){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void display(vector<vector<long>> &result){
    for(auto x : result){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> pfSum(vector<vector<int>> &A){
    vector<vector<long>> pSum(A.size(), vector<long>(A[0].size(),0));
    for(int i = 0; i<A.size();i++){
        pSum[i][0] = A[i][0];
        for(int j = 1; j<A[0].size();j++){
            pSum[i][j] = pSum[i][j-1] + A[i][j];
        }
    }

    for(int j = 0; j<pSum[0].size();j++){
        for(int i = 1; i<pSum.size();i++){
            pSum[i][j] += pSum[i-1][j];
        }
    }
    display(pSum);
    return A;
}


vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E){
    vector<vector<long>> pSum(A.size(), vector<long>(A[0].size(),0));
    for(int i = 0; i<A.size();i++){
        pSum[i][0] = A[i][0];
        for(int j = 1; j<A[0].size();j++){
            pSum[i][j] = pSum[i][j-1] + A[i][j];
        }
    }

    for(int j = 0; j<pSum[0].size();j++){
        for(int i = 1; i<pSum.size();i++){
            pSum[i][j] += pSum[i-1][j];
        }
    }
    vector<int> result;
    for(int i =0; i<B.size();i++){
        int a1 = B[i]-1;
        int b1 = C[i]-1;
        int a2 = D[i]-1;
        int b2 = E[i]-1;
        long sum = pSum[a2][b2];
        if(a1>0){
            sum -= pSum[a1-1][b2];
        }
        if(b1>0){
            sum -= pSum[a2][b1-1];
        }
        if(a1>0 && b1>0){
            sum += pSum[a1-1][b1-1];
        }
        int res = 0;
        if(sum <0){
            res = (int)(sum% 1000000007 + 1000000007);
        }else{
            res = (int)(sum % 1000000007);
        }
        result.push_back(res);
    }

    return result;
}

int main()
{
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> B = {1,2};
    vector<int> C = {1,2};
    vector<int> D = {2,3};
    vector<int> E = {2,3};

    // vector<vector<int>> A = {
    //     {5, 17, 100, 11},
    //     {0, 0,  2,   8}
    //     //{7,8,9}
    // };

    // vector<int> B = {1,1};
    // vector<int> C = {1,4};
    // vector<int> D = {2,2};
    // vector<int> E = {2,4};


    //vector<vector<int>> result = pfSum(A);
    //display(result);

    vector<int> result = solve(A,B,C,D,E);
    for(auto x : result){
        cout<< x<<" ";
    }

    return 0;
}