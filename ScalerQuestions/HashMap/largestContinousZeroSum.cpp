#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>


using namespace std;

vector<int> lszero(vector<int> &A){
    unordered_map<int, vector<int>> map;

    vector<int> temp;
    temp.push_back(0);
    map.insert(make_pair(A[0], temp));

    int prev = A[0];
    vector<int> pfsum;
    pfsum.push_back(prev);
    for(int i = 1; i<A.size(); i++){
        int sum = prev + A[i];
        prev = sum;
        pfsum.push_back(prev);
        if(map.find(sum) != map.end()){
            map[sum].push_back(i);
        }else{
            vector<int> sometemp;
            sometemp.push_back(i);
            map.insert(make_pair(sum,sometemp));
        }
    }
    int msize = -1;
    int mstart = -1;
    int mend = -1;
    for(int i = 0; i<A.size(); i++){
        int element = pfsum[i];
        if(map.find(pfsum[i]) != map.end() && pfsum[i] == 0){
            int size = map[pfsum[i]][map[pfsum[i]].size()-1] + 1;
            if(size > msize){
                msize = size;
                mstart = -1;
                mend = map[pfsum[i]][map[pfsum[i]].size()-1];
            }
        }

        else if(map.find(pfsum[i]) != map.end() && map[pfsum[i]].size() >1){
            int size = abs(map[pfsum[i]][0] - map[pfsum[i]][map[pfsum[i]].size()-1]);    
            if(size > msize){
                msize = size;
                mstart = map[pfsum[i]][0];
                mend = map[pfsum[i]][map[pfsum[i]].size()-1];
            }
        }
    }    
    vector<int> result;
    for(int i = mstart + 1; i<=mend; i++){
        result.push_back(A[i]);
    }
    return result;
}

int main()
{
    vector<int> A = {1,2,-2,4,-4};
    vector<int> result = lszero(A);
    for(auto x : result){
        cout<<x<<" "; 
    }
    return 0;
}