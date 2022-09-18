#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int longestConsecutive(const vector<int> &A){
    unordered_set<int> set;

    for(auto x: A){
        set.insert(x);
    }

    int maxSize = -1;
    for(int i = 0; i<A.size(); i++){
        int element = A[i];
        if(set.find(element-1) != set.end()){
            continue;
        }
        int size = 0; 
        while(set.find(element) != set.end()){
            element++;
            size++;
        }
        maxSize = max(maxSize, size);
    }
    return maxSize;
}

int main()
{
    vector<int> A = { 6, 4, 5, 2, 3};
    cout<<longestConsecutive(A)<<endl;
    return 0;
}