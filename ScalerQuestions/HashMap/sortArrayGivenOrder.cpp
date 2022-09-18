#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B){
    unordered_map<int,int> sa;
    unordered_set<int> sb;

    for(auto x : A){
        if(sa.find(x) != sa.end() ){
            sa[x]++;
        }else{
            sa.insert(make_pair(x,1));
        }
    }
    for(auto x : B){
        sb.insert(x);
    }

    vector<int> tempA;

    for(auto x : A){
        if(sb.find(x) == sb.end()){
            tempA.push_back(x);
        }
    }

    sort(tempA.begin(), tempA.end());
    vector<int> result;
    for(auto x : B){
        if(sa.find(x) == sa.end()){
            sb.erase(x);
        }else{
            int j = 0;
            while(j<sa[x]){
            result.push_back(x);
            j++;
            }
        }
    }   

    for(auto x : tempA){
        result.push_back(x);
    }

    return result;
}

int main()
{   
    vector<int> A = {10, 2, 18, 16, 16, 16};
    vector<int> B = {3, 13, 2, 16, 4, 19 };

    vector<int> result = solve(A,B);
    for(auto x : result){
        cout<<x<<" ";
    }
    
    return 0;
}