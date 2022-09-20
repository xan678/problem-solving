#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//Brute Force Solution
vector<int> solve(vector<int> &A, vector<vector<int>> &B){
    vector<int> result;

    for(auto x : B){
        int l1 = x[0]; //0
        int r1 = x[1]; //1
        int l2 = x[2]; //2
        int r2 = x[3]; //3

        unordered_set<int> set1;
        unordered_set<int> set2;

        while(l1 <= r1){
            set1.insert(A[l1]);
            l1++;   
        }

        while(l2 <= r2){
            set2.insert(A[l2]);
            l2++;   
        }    

        if(set1.size() != set2.size()){
            result.push_back(0);
            continue;
        }
        l1 = x[0];
        l2 = x[2];

        bool flag = false;
        while (l1<=r1)
        {   

            if(set2.find(A[l1]) == set2.end()){
                result.push_back(0);
                flag = true;
                break;
            }
            l1++;
        }

        if(flag){
            continue;
        }
        bool flag2 = false;
        while (l2<= r2)
        {
            if(set1.find(A[l2]) == set1.end()){
                result.push_back(0);
                flag2 = true;
                break;
            }
            l2++;
        }
        if(flag2){
            continue;
        }        
        result.push_back(1);
    }

    return result;
}

int main()
{
    vector<int> A = {4, 3, 2, 1};
    vector<vector<int>> B = {
        {0, 1, 2, 3},
        {2, 2, 3, 3},
        {1, 3, 0, 0},
        {3, 3, 1, 2},
        {1, 2, 2, 3}
    };

    vector<int> result = solve(A,B);
    for(auto x : result){
        cout<<x<<" ";
    }
    return 0;
}