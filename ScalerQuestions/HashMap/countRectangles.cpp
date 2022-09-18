#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

int solve(vector<int> &A, vector<int> &B){
    typedef pair<int,int> pairs;
    set<pairs> set;

    for(int i = 0; i< A.size() ;i++){
        set.insert(make_pair(A[i], B[i]));
    }

    int count = 0;
    for(int i = 0; i<A.size() ;i++){
        for(int j = i+1; j<A.size() ; j++){
            if(A[i] == A[j] || B[i] == B[j] ){
                continue;
            }
            
            if(set.find(make_pair(A[i],B[j])) != set.end() && set.find(make_pair(A[j],B[i])) != set.end()){
                count++;
            }
        }
    }
    return count/2;
}

int main()
{
    vector<int> A = {1, 1, 2, 2, 3, 3};
    vector<int> B = {1, 2, 1, 2, 1, 2};

    cout<<solve(A,B);

    return 0;
}