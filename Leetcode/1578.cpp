#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    
    int i = 0;
    int result = 0;
    while(i<colors.size()){
        if(colors[i] == colors[i+1]){
            int temp = neededTime[i];
            while (colors[i] == colors[i+1] )
            {   
                //colors.assign('-',i);
                temp = min(temp, neededTime[i+1]);
                i++;
            }
            result += temp;
            //i--;

        }
            i++;
    }
    return result;
}

int main()
{   
    string  colors = "aabaa";
    vector<int> B = {1,2,3,4,1};
    cout<<minCost(colors,B);
    
    return 0;
}