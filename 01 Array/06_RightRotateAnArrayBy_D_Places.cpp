#include<bits/stdc++.h>
using namespace std;

//We'll directly jump to optimal solution

class Rotate
{
    private:
        void reverse(vector<int>& arr, int left, int right)
        {
            while(left < right)
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }

    public:
        void rightRotate(vector<int>& arr, int n, int k)
        {
            k = k % n;

            reverse(arr, n-k, n-1);
            reverse(arr, 0, n-k-1);
            reverse(arr, 0, n-1);
        }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 2;

    Rotate obj;
    obj.rightRotate(arr, n, k);

    for(auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}