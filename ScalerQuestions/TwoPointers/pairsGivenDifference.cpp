#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int solve(vector<int> &A, int B){
    int resultCount = 0;
    int i = 0, j=1;
    sort(A.begin(), A.end());
    
    for(auto x : A){
        cout<<x<<" ";
    }
    cout<<endl;

    int pair2 = -1, pair1 = -1;
    while (j<A.size())
    {
        int diff = abs(A[j]-A[i]);

        if(diff == B){
            if(pair1 != A[j], pair2 != A[i]){
                resultCount++;
                pair1 = A[j];
                pair2 = A[i];
            }
            i++; j++;
        }else if(diff>B){
            i++;

            if(i==j){
                j++;
            }
        }else{
            j++;
        }
    }
    
    return resultCount;
}

int main()
{   
    vector<int> A = {8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2, 8, 2, 2, 6};
    int B = 3;
    cout<<solve(A,B)<<endl;
    return 0;
}