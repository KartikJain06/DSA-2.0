#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

        void BruteRotate(vector<int> &arr, int k)
        {
            int temp = arr[0];
            int n = arr.size();

            k = k % n;

            while (k--)
            {
                int temp = arr[0];

                for(int i = 1; i < n; i++)
                {
                    arr[i-1] = arr[i];
                }

                arr[n-1] = temp;
            }

        }
        
        void OptimalRotateLeft(vector<int> &arr, int k)
        {

            int n = arr.size();
            k = k % n;

            reverseArray(arr, 0, k-1);
            reverseArray(arr, k, n-1);
            reverseArray(arr, 0, n-1);

        }

        void OptimalRotateRight(vector<int> &arr, int k)
        {

            int n = arr.size();
            k = k % n;

            reverseArray(arr, n-k, n-1);
            reverseArray(arr, 0, n-k-1);
            reverseArray(arr, 0, n-1);

        }

        void reverseArray(vector<int> &arr, int left, int right)
        {
            while(left < right)
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }

};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Solution obj;

    obj.OptimalRotateRight(arr, 3);

    for(auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}