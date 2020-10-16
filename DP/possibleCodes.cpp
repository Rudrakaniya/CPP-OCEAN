// The number of possible codes which can be generated from the given array
// In the given problem 1 = a, 2 = b and so on...
#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int numOfCodes(int *arr, int size, int *DP)
{
    // Checking the base condition.
    if ((size == 1) or (size == 0))
    {
        return 1;
    }

    // Checking if the case is already solved.
    if (DP[size] > 0)
    {
        return DP[size];
    }

    int output = numOfCodes(arr, size - 1, DP);

    if ((arr[size - 2] * 10 + arr[size - 1]) < 27)
    {
        output += numOfCodes(arr, size - 2, DP);
    }

    DP[size] = output;

    return output;
}

// Iterative solution
int numOfCodes_i(int *arr, int size)
{
    int *outputDP = new int[size + 1];

    // Base cases
    outputDP[0] = 1;
    outputDP[1] = 1;

    for (int i = 2; i <= size; ++i)
    {
        outputDP[i] = outputDP[i - 1];

        if ((arr[i - 2] * 10 + arr[i - 1]) < 27)
        {
            outputDP[i] += outputDP[i - 2];
        }
    }

    int ans = outputDP[size];

    delete[] outputDP;
    return ans;
}

int32_t main()
{
    // int arr[] = {1, 1, 2, 3};
    int arr[] = {2, 3, 1, 4};
    int size = 4;

    int DP[size + 1] = {0};

    cout << "The number of possible codes which can be generated from the given array is  = ";
    cout << numOfCodes(arr, size, DP) << endl;

    cout << "With recursive approch  =  " << numOfCodes_i(arr, size) << endl;

    return 0;
}