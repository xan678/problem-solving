#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s;

    s.push(0);
    span[0] = 1;

    for (int i = 1; i <= n - 1; i++)
    {
        int currentPrice = prices[i];
        while (!s.empty() && prices[s.top()] <= currentPrice)
        {
            s.pop();
        }

        if (s.empty())
        {
            span[i] = 1;
        }
        else
        {
            int prev = s.top();
            span[i] = i - prev;
        }

        s.push(i);
    }
}

void insertAtBotton(stack<int> &s, int data)
{
    if (s.size() == 0)
    {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBotton(s, data);
    s.push(temp);
    return;
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 2)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(a);
        s.push(b);
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBotton(s, temp);
    return;
}

int reverseNumber(int number)
{
    if (number == 0)
        return 0;
    bool isNegative;
    if (number <= 0)
    {
        isNegative = true;
        number = -number;
    }

    stack<int> s;
    int digit = 0;
    while (number != 0)
    {
        s.push(number % 10);
        number = number / 10;
        digit++;
    }
    int i = 0;
    while (s.size() != 0 && i < digit)
    {
        number = number + s.top() * pow(10, i);
        i++;
        s.pop();
    }

    return isNegative ? -number : number;
}

int main(int argc, char const *argv[])
{
    int number = 0;
    cout << reverseNumber(number);
    return 0;
}
