#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

void displayMap(unordered_map<int,int> map){
    for(auto x : map){
        cout<<x.first<<" -> "<<x.second<<endl;
    }
}

vector<int> dNums(vector<int> &A, int B){
    unordered_map<int,int> map;
    if(B>A.size()){
        return {};
    }
    for(int i = 0; i<B;i++){
        if(map.find(A[i]) != map.end()){
            map[A[i]]++;
        }else{
            map.insert(make_pair(A[i],1));
        }
    }  
    vector<int> result;
    result.push_back(map.size());

    for(int i = B; i<A.size(); i++){
        int element = A[i-B];
        map[element]--;
        if(map[element] == 0){
            map.erase(element);
        }
        if(map.find(A[i]) != map.end()){
            map[A[i]]++;
        }else{
            map.insert(make_pair(A[i], 1));
        }

        result.push_back(map.size());
    }

    return result;
}

int main()
{
    vector<int> A = {2, 7, 7, 81, 81 };
    int B = 1;
    vector<int> result = dNums(A,B);
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}