#include<iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<list>
using namespace std;

class Node{

public:
    string name;
    list<string> nbrs;

    Node(string name){
        this->name = name;
        //this->nbrs = new list<string>();
    }
};

class Graph{
    //Hashmap<string, node *> for the nodes
    unordered_map<string, Node*> m;

public:
    Graph(vector<string> cities){
        for (auto city : cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir = true){
        m[x]-> nbrs.push_back(y);
        if(undir){
            m[y] -> nbrs.push_back(x);
        }
    }

    void printAdjList(){
        for( auto d : this->m){
            cout<<d.first<<" --> ";
            for(auto p : d.second->nbrs){
                cout<<p<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    
    //All Nodes
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);

    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");
    
    g.printAdjList();
    // Node *n = new Node("Ankush");
    // cout<<n->name<<endl;

    // return 0;
}