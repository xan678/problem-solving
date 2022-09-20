#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool checkFunc(vector<int> &A, int B, int space){
   int last = A[0];
   int cowplaced = 1;

   for(int i= 1; i<A.size() ;i++){
        if(A[i] - last >= space){
            last =  A[i];
            cowplaced++;

            if(cowplaced == B){
                return true;
            }
        }
   }
   return false;
}

int solve(vector<int> &A, int B){
    sort(A.begin(), A.end());
    int start = A[0];
    int end = A[A.size()-1] - A[0];

    int ans = 0;
    while(start <= end){
        int mid = start + (end - start)/2;
        cout<<start <<" "<<end<<" "<<mid<<endl;
        bool flag = checkFunc(A, B, mid);
        if(flag){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    return ans;
}

int main()
{
    vector<int> A = {5, 17, 100, 11 };
    cout<<solve(A,2);
    //cout<<checkFunc(A,3,3);
    return 0;
}