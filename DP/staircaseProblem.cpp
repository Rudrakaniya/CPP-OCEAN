// Staircase problem
// A kid can only take 1-step, 2-steps or 3-steps at a time to climb n steps.
// We need to find, how many diff. ways kid can take these steps.
// The solution for this problem will be similar to fibonacci sequence
// Just th diff. is we'll be adding last three values.
// Time complexity  =  O(n)
#include <bits/stdc++.h>
using namespace std;

int possibleWays(int n, int *DP)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (DP[n] > 0)
    {
        return DP[n];
    }

    int ans = possibleWays(n - 1, DP) + possibleWays(n - 2, DP) + possibleWays(n - 3, DP);
    DP[n] = ans;
    
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;

    int DP[n + 1] = {0};

    cout << "Number of different ways kid can take are  =  ";
    cout << possibleWays(n, DP) << endl;
    return 0;
}