#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int colorful(int A){

    unordered_set<int> set;

    string temp = "";
    int x = A;
    int size = 0;
    while (x)
    {   
        char ch = '0' + (x%10);
        x = x/10;
        temp.insert(temp.begin(), ch);
    }
    
    for(int i = 0; i<temp.size(); i++){
        int prod = 1;
        for(int j = i; j<temp.size(); j++){
            prod = prod* (temp[j] - '0');
            if(set.find(prod) != set.end()){
                return 0;
            }
            set.insert(prod);
        }
    }
    return 1;
}

int main()
{
    cout<<colorful(236)<<endl;
    return 0;
}