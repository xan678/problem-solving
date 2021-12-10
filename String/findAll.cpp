#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};


}

int main()
{
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    vector<int> result = stringSearch(bigString,smallString);
    for(auto x : result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}