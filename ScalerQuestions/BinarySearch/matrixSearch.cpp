#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int searchMatrix(vector<vector<int>> &A, int B){

    int n = A.size();
    int m = A[0].size();

    cout<<n<<endl;
    int start = 0;
    int end = n*m -1 ;

    
    int ans = 0;
    while (start <= end)
    {
        int mid = (start + end)/2;
        cout<<mid<<endl;
        int row = mid/m;
        int col = mid%m;

        if(A[row][col] == B){
            ans = 1;
            break;
        }
        if(A[row][col] > B){
            end = mid -1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{   
    vector<vector<int>> A = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };
    int B = 30;
    
    cout<<searchMatrix(A,B)<<endl;
    return 0;
}