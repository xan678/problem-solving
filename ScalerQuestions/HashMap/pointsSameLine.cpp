#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>


using namespace std;

int solve(vector<int> &A, vector<int> &B){
    set<pair<int,int>> map;

    for(int i = 0; i<A.size() ;i++){
        map.insert(make_pair(A[i], B[i]));
    }

}

int main()
{
    
    return 0;
}