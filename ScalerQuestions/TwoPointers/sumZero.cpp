#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &A){
    if(A.size() == 0){
        return {};
    }
    sort(A.begin(), A.end());
    int i = 0;
    int previous = INT_MIN;
    vector<vector<int>> result;
    while(i<A.size()-2){
        if(A[i] == previous){
            i++;
            continue;
        }
        int j = i+1;
        int k = A.size()-1;
        int prvj = INT_MIN;
        int prvk = INT_MIN;
        while(j<k){
            int sum = A[i] + A[j] + A[k];
            if(sum<0){
                j++;
            }
            if(sum>0){
                k--;
            }
            if(sum == 0){
                if(A[j] != prvj && A[k] != prvk){
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[k]);
                    result.push_back(temp);

                    prvj = A[j];
                    prvk = A[k];
                }
                j++;
                k--;
            }
        }

        previous = A[i];
        i++;
    }

    return result;
}

int main()
{   
    vector<int> A = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3 };
    vector<vector<int>> result = threeSum(A);
    sort(result.begin(), result.end());
    for(auto x: result){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}