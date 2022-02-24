#include<iostream>
#include <vector>
#include <string>
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

    void dfsHelper(int node, bool *visited){
        visited[node] = true;
        cout<<node<<",";
        for(auto x : l[node]){
            if(!visited[x]){
                dfsHelper(x, visited);
            }
        }
        return;
    }

    void dfs( int source){
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
        return;
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

    g.dfs(1);

    return 0;
}