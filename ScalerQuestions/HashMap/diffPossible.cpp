#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

int diffPossible(const vector<int> &A, int B){
    unordered_map<int,int> map;

    for(auto x : A){
        if(map.find(x) != map.end()){
            map[x]++;
        }else{
            map.insert(make_pair(x,1));
        }
    }

    for(int i = 0; i<A.size(); i++){
        int look = A[i] - B;

        if(map.find(look) != map.end()){

            if(look == A[i] && map[look] <2){
                continue;
            }
            return 1;
        }
    }

    return 0;
}

int main()
{
    const vector<int> A = {1,3,2};
    int B = 0;

    cout<<diffPossible(A, B);
    return 0;
}