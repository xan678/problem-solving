#include<iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

//To Do during revision
bool discussSectionSolutionDFS(vector<vector<int>>& rooms){

}

bool discussSectionSolutionBFS(vector<vector<int>>& rooms){
    unordered_set<int> visited;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        visited.insert(f);
        for(auto x : rooms[f]){
            if(visited.find(x) == visited.end()){
                q.push(x);
            }
        }
    }

    return visited.size() == rooms.size();
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> isUnlocked(rooms.size(),false);
    isUnlocked[0] = true;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto x : rooms[f]){
            if(isUnlocked[x] ==false){
                q.push(x);
                isUnlocked[x] = true;
            }
        }
    }

    for(auto x : isUnlocked){
        if(x == false ){
            return false;
        }
    }

    return true;
}

int main(){
    
    vector<vector<int>> rooms = {
        {1,3},{3,0,1},{2},{0}
    };
    //cout<<canVisitAllRooms(rooms);
    //cout<<discussSectionSolutionBFS(rooms)<<endl;
    return 0;
}