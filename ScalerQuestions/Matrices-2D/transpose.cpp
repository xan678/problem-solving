#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A)
{
    vector<vector<int>> result(A[0].size(),vector<int>(A.size()));
    //cout<<result.size()<<" "<<result[0].size();
    for (int i = 0; i < A.size(); i++)
    {   
        //result[i] =  vector<int>(A[i].size());
        for (int j = 0; j < A[i].size(); j++)
        {
            result[j][i] =  A[i][j];
        }

    }

    return result;
}

int main()
{
    vector<vector<int>> A = {
        {21, 62, 16, 44, 55, 100, 16, 86, 29},
  {62, 72, 85, 35, 14, 1, 89, 15, 73},
  {42, 44, 30, 56, 25, 52, 61, 23, 54},
  {5, 35, 12, 35, 55, 74, 50, 50, 80},
  {2, 65, 65, 82, 26, 36, 66, 60, 1},
  {18, 1, 16, 91, 42, 11, 72, 97, 35},
  {23, 57, 9, 28, 13, 44, 40, 47, 98}
        };
    vector<vector<int>> result = solve(A);
    for(auto x : result){
        for(auto i : x){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}