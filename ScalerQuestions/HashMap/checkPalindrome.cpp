#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int solve(string A){
    unordered_map<char, int> map;

    for(auto x : A){
        if(map.find(x) != map.end()){
            map[x]++;
        }else{
            map.insert(make_pair(x,1));
        }
    }

    int countOdds = 0;
    int countEvens = 0;
    for(auto x : map){
        if(x.second % 2 != 0){
            countOdds++;
        }

        if(x.second % 2 == 0){
            countEvens++;
        }

        if(countOdds > 1){
            return 0;
        }
    }

    return 1;
}

int main()
{
    cout<<solve("abbaee")<<endl;   
    return 0;
}