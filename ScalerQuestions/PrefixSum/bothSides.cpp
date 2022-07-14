#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<long long> prefixSum(n);

    prefixSum[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    int maxSum = INT_MIN;

    int front = 0;
    int last = B;
    while (front <= B and last >= 0)
    {
        int frontSum = (front == 0) ? 0 : prefixSum[front - 1];
        int lastSum = (last == 0) ? 0 : prefixSum[n - 1] - prefixSum[n - last - 1];
        maxSum = max(maxSum, frontSum + lastSum);

        cout << frontSum << " " << lastSum << endl;
        front++;
        last--;
    }
    return maxSum;
}

int main()
{
    // vector<int> A = {-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35};
    // int B = 48;

    // vector<int> A = {5, -2, 3, 1, 2};
    // int B = 3;

    // vector<int> A = {-712, -894, 40, -58, 264, -352, 446, 805, 890, -271, -630, 350, 6, 101, -607, 548, 629, -377, -916, 954, -244, 840, -34, 376, 931, -692, -56, -561, -374, 323, 537, 538, -882, -918, -71, -459, -167, 115, -361, 658, -296, 930, 977, -694, 673, -614, 21, -255, -76, 72, -730, 829, -223, 573, 97, -488, 986, 290, 161, -364, -645, -233 };
    // int B = 34;

    vector<int> A = {2, 3, 4, 3, 4, 4, 1 };
    int B = 6;

    cout << solve(A, B);
    return 0;
}