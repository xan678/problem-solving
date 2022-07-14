#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(string A)
{
    vector<int> onesTillZeroes;

    int count = 0;
    for (auto x : A)
    {
        if (x == '1')
        {
            count++;
        }
        if (x == '0')
        {
            onesTillZeroes.push_back(count);
            count = 0;
        }
    }
    if (count != 0)
    {
        onesTillZeroes.push_back(count);
    }
    int i = 0;
    int max = INT_MIN;
    while (i <= onesTillZeroes.size() - 2)
    {
        int x = onesTillZeroes[i] + onesTillZeroes[i + 1] + 1;
        if (max < x)
        {
            max = x;
        }
        i++;
    }
    return max;
}

int main()
{
    string A = "1111111000000";
    int p = solve(A);
    cout << p << endl;
    return 0;
}