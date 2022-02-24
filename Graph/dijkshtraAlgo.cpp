#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

//Weighted graph
class Graph{
    //Pointer to the array of list
    list<pair<int, int>> *l;
    int V;
    //Dynamic allocation as the size of the graph is not known
public:
    Graph(int v){
        V = v;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int i, int j, int wt,bool undir=true){
        l[i].push_back({wt,j});
        if(undir){
            l[j].push_back({wt,i});
        }
    }

    void printAdjList() {
        for(int i =0; i< V;i++){
            cout<<i<<"-->";
            for( auto node: l[i]){
                cout<<node.first<<":"<<node.second<<"  ";
            }
            cout<<endl;
        }
    }

    int dijkstra(int src, int dest){

        //Need two data structurs : vector and set
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        //init
        dist[src] = 0;
        s.insert({0,src});
        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            //cout<<node<<" "<<distTillNow<<endl;
            s.erase(it); //Pop

            for(auto nbrPair : l[node]){
               int nbr = nbrPair.second;
               int currentEdge = nbrPair.first;

               if(distTillNow + currentEdge < dist[nbr]){
                   //remove if nbr already exist in the the set

                    auto f = s.find({dist[nbr],nbr});
                    if(f != s.end()){
                        s.erase(f);
                    }
                   dist[nbr] = distTillNow + currentEdge;
                   s.insert(make_pair(dist[nbr], nbr));
               }
            }

        }

        for(int i = 0; i < V; i++){
            cout<<i <<":"<<dist[i]<<endl;
        }
        return dist[dest];
    }
};

int main(int argc, char const *argv[])
{
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    g.printAdjList();
    cout<<endl;
    cout<<"_____________________________"<<endl;
    cout<<endl;
    g.dijkstra(0,4);
    return 0;
}
