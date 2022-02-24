#include<iostream>
#include <vector>
#include <string>
#include<queue>
#include<list>
using namespace std;

class Graph{
    //Pointer to the array of list
    list<int> *l;
    int V;
    //Dynamic allocation as the size of the graph is not known
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList() {
        for(int i =0; i< V;i++){
            cout<<i<<"-->";
            for( auto node: l[i]){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }

    void bfs ( int source){
        queue<int>q;
        bool * visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<" ";
            q.pop();
            for(auto x : l[f]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};

int main(){
    
    Graph g(7);
    
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs(1);
    return 0;
}