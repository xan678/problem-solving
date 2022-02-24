#include<iostream>
#include <vector>
#include <string>
#include<vector>
#include<list>
#include<climits>
using namespace std;

int findCenterFast (vector<vector<int>>& edges){
    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
}

int findCenter(vector<vector<int>>& edges) {
    vector<int> nodes(edges.size(),0);
    int max = INT_MIN; 
    int element = 0;  
    for(auto x : edges){
        nodes[x[0]]++;
        nodes[x[1]]++;

        cout<<x[0]<<" "<<x[1]<<endl;
        if(nodes[x[0]] > max){
            max = nodes[x[0]];
            element = x[0]; 
        } 
        else if(nodes[x[1]] > max){
            max = nodes[x[1]];
            element = x[1]; 
        }
    }
    return element;   
}

int main(){
    vector<vector<int>> edges = {
        {1,2},{5,1},{1,3},{1,4}
    };  

    //int ans = findCenter(edges);
    int ans = findCenterFast(edges);
    cout<<ans;
    return 0;
}


//e[0][0] == e[1][0] or e[0][0] == e[1][1]