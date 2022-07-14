#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve2(int A)
{
    if (A / 10 == 0)
    {
        return A;
    }
    return A % 10 + solve2(A / 10);
}

int solve(int A){
    while(A>=10){
        A = solve2(A);
        cout<<A<<endl;
    }

    cout<<A<<endl;
    return A == 1 ? 1 : 0;
}

int main()
{
    int A = 1291;
    cout << solve(A) << endl;
    return 0;
}