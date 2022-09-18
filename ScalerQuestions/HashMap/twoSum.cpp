#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> twoSum(const vector<int> &A, int B){
    unordered_map <int, vector<int>> map;
    for(int i = 0; i<A.size(); i++){
        if(map.find(A[i]) != map.end()){
            map[A[i]].push_back(i);
        }
        else{
            vector<int> temp;
            temp.push_back(i);
            map.insert(make_pair(A[i], temp));
        }
    }

    // for(auto x : map){
    //     cout<<x.first<<" : ";
    //     for(auto y : x.second){
    //         cout<< y<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> result;
    int index1 = 0;
    int index2 = INT_MAX;
    for(int i = 0; i<A.size(); i++){
        int findNum = B-A[i];
        if(map.find(findNum) != map.end()){
            if(findNum == A[i]){
                int temp1 = i+1;int temp2;
                for(auto x : map[findNum]){
                    if(x != i){
                        temp2 = x+1;
                        break;
                    }
                }

                if(temp2 < index2 && temp1 < temp2){
                    index1 = temp1;
                    index2 = temp2;
                }

            }else{

                if(map[findNum][0] + 1 < index2 && i+1 < map[findNum][0] + 1){
                    index1 = i+1;
                    index2 = map[findNum][0] + 1;
                }
            }
        }
    }

    if(index1 != 0 && index2 != INT_MAX){
        result.push_back(index1);
        result.push_back(index2);
    }
    return result;
}

int main()
{
    vector<int> A = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
    vector<int> result = twoSum(A,-3);
    for(auto x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}