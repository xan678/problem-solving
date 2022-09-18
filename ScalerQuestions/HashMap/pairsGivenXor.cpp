#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int solve(vector<int> &A, int B){
    unordered_set<int> set;

    int count = 0;
    for(auto x : A){
        set.insert(x);
    }

    for(auto x : A){
        int p = B^x;
        if(set.find(p) != set.end()){
            count++;
            set.erase(x);
            set.erase(p);
        }
    }

    return count;
}


int main()
{
    vector<int> A = {5, 4, 10, 15, 7, 6};
    int B = 5;

    cout<<solve(A,B);
    return 0;
}