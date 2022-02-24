#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<string>
#include<vector>
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

    void addEdge(int i, int j, bool undir=false){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void topological_sort(){
        vector<int> indegree(V,0);
        //Iterate over all the nodes to calculate their indegree
        for(int i=0; i<V;i++){

            for(auto nbr : l[i]){
                indegree[nbr]++;
            }
        }
        queue<int> q;
        //Push nodes in the queue which have indegree of 0
        for(int i = 0; i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        cout<<endl;
        
        //Perform bfs;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            cout<<f<<" ";
            for(auto nbr : l[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }    
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
};

int main(int argc, char const *argv[])
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);

    //g.printAdjList();
    g.topological_sort();
    return 0;
}