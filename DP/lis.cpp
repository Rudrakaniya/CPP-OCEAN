// DP approch for "Longest Increasing Subsequence"
// Time complexity  =  O(n^2)
#include <bits/stdc++.h>
using namespace std;

int lis(int *arr, int n)
{
    int *output = new int[n];
    output[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        int possibleAns = 1;

        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > arr[i])
            {
                continue;
            }

            possibleAns = output[j] + 1;

            if (possibleAns > output[i])
            {
                output[i] = possibleAns;
            }
        }
    }

    int ans{0};
    for (int i = 0; i < n; ++i)
    {
        if (output[i] > ans)
        {
            ans = output[i];
        }
    }
    delete[] output;
    return ans;
}

int32_t main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Longest increasing subsequence of the above array is  =  ";
    cout << lis(arr, size) << endl;

    return 0;
}