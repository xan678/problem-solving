#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int solve(string A)
{
    int mod = 10003;

    unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    auto x = A.end() - 1;
    int ans = 0;
    int countTillVowel = 0;

    while (x >= A.begin())
    {
        if (set.find(*x) != set.end())
        {
            countTillVowel++;
            ans = (ans % mod + countTillVowel % mod) % mod;
        }
        else
        {
            countTillVowel++;
        }
        x--;
    }

    return ans;
}

int main()
{
    string A = "ABEC";

    cout << solve(A) << endl;
    return 0;
}