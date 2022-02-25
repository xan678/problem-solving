#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner
{

public:
    StockSpanner()
    {
    }
    int next(int price)
    {
        return 0;
    }
};

vector<int> nextGreaterElement(vector<int> v)
{
    stack<int> s;
    int n = v.size();
    vector<int> result(n, 0);
    //s.push(0);
    for (int i = 0; i <= n - 1; i++)
    {
        //cout << "ITR" << i << endl;
        while (!s.empty() && v[i] > v[s.top()])
        {
            if (v.size() == 1)
            {
                break;
            }
            result[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        result[s.top()] = -1;
        s.pop();
    }

    return result;
}
/*
vector<int> stockSpanner(vector<int> &stocks)
{
    stack<int> s;
    vector<int> span(stocks.size(), 0);
    int n = stocks.size();
    s.push(0);
    span[0] = 1;
    for (int i = 1; i <= stocks.size() - 1; i++)
    {
        int current = stocks[i];
        while (!s.empty() && stocks[s.top()] <= current)
        {
            s.pop();
        }

        if (s.empty())
        {
            span[i] = 1;
        }
        else
        {
            span[i] = i - s.top();
        }
        s.push(i);
    }
    return span;
}
*/

int main(int argc, char const *argv[])
{
    vector<int> v = {4, 5, 2, 25};

    vector<int> result = nextGreaterElement(v);
    cout << "out of loop" << endl;
    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}
