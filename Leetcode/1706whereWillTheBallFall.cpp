#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> findBall(vector<vector<int>> & grid){
    int i = 0;
    int n = grid[0].size();

    vector<int> result;
    while( i< n){
        bool flag = false;
        int j = 0;
        int ball = i;
        while( j < grid.size()){
            
            if(grid[j][ball] == -1){
                if(ball>0 && grid[j][ball-1] == -1){
                    flag = true;
                    j++;
                    ball--;
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(grid[j][ball] == 1){
                if(ball < n-1 && grid[j][ball+1] == 1){
                    flag = true;
                    j++;
                    ball++;
                    continue;
                }else{
                    flag = false;
                    break;
                }
            }
        }

        if(flag) result.push_back(ball);
        else result.push_back(-1);
        i++;
    }
    return result;
}

int main()
{
    vector<vector<int>> grid = {
        {1,1,1,-1,-1},
        {1,1,1,-1,-1},
        {-1,-1,-1,1,1},
        {1,1,1,1,-1},
        {-1,-1,-1,-1,-1}
    };

    vector<vector<int>> grid2 = {
        {1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,-1},
        {1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,-1}
    };

    vector<int> result = findBall(grid2);

    for(auto x : result) cout<<x<<" ";
    cout<<endl;
    return 0;
}