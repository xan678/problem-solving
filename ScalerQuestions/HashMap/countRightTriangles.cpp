#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

void displayMap(unordered_map<int,int> map){
    for(auto x : map){
        cout<<x.first << " -> "<<x.second<<endl;
    }
    cout<<endl;
}

int solve(vector<int> &A, vector<int> &B){
    int mod = 1000*1000*1000 + 9;

    unordered_map <int,int> x;
    unordered_map <int,int> y;

    for(int i = 0; i<A.size();i++){
        if(x.find(A[i]) != x.end()){
            x[A[i]]++;
        }else{
            x.insert(make_pair(A[i],1));
        }

        if(y.find(B[i]) != y.end()){
            y[B[i]]++;
        }else{
            y.insert(make_pair(B[i],1));
        }
    }

    long result = 0;

    for(int i = 0; i<A.size();i++){
        long res = (((x[A[i]]-1)%mod) * ((y[B[i]]-1)%mod))%mod;
        result = result %mod + res;
    }

    return (int)(result%mod);
}

int main()
{
    vector<int> A = {1, 1, 2, 3, 3};
    vector<int> B = {1, 2, 1, 2, 1};

    cout<<solve(A,B);
    return 0;
}