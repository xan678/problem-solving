#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> solve(vector<int> &A, int B){
    unordered_map<long,int> map;
    vector<long> pf(A.size());
    pf[0] = A[0];
    map.insert(make_pair(pf[0], 0));

    for(int i = 1; i<A.size(); i++){
        pf[i] = pf[i-1] + A[i];
        map.insert(make_pair(pf[i], i));
    }

    vector<int> result;
    for(int i = 0; i<pf.size();i++){
        if(i == 0 && map.find(B) != map.end()){
            int start = 0;
            int end = map[B];
            while(start <= end){
                result.push_back(A[start]);
                start++;
            }
            return result;
        }
        if(i > 0 && map.find(B + pf[i-1]) != map.end()){
            int start = i;
            int end = map[B + pf[i-1]];
            
            while(start <= end){
                result.push_back(A[start]);
                start++;
            }

            return result;
        }
    }

    result.push_back(-1);
    return result;
}

int main()
{
    vector<int> A = {5, 10, 20, 100, 105};
    int B = 110;
    vector<int> result = solve(A,B);
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}