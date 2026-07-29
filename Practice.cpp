#include <bits/stdc++.h>
using namespace std;

int lastOccurence(vector<int> &arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int floor = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= target)
        {
            floor = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return floor;
}

pair<int, int> firstOccurence(vector<int> &arr, int target)
{
    int n = arr.size();

    if (n == 0)
        return {-1, -1};

    int low = 0;
    int high = n - 1;

    int startInd = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target)
        {
            startInd = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (startInd == -1 || startInd >= n || arr[startInd] != target)
        return {-1, -1};

    return {startInd, lastOccurence(arr, target)};
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 5, 6, 7, 7, 8, 8, 8, 8, 9, 10, 11};

    pair<int, int> ans = firstOccurence(arr, 8);

    cout << ans.first << " to " << ans.second;

    return 0;
}