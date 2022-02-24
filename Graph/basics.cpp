#include<iostream>
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
};

int main(int argc, char const *argv[])
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.printAdjList();
    return 0;
}
