#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

    int DuplicatedorNot(vector<int> &arr)
    {
        
        int n = arr.size();

        int i = 0;
        for(int j = 1; j < n; j++)
        {
            if(arr[j] != arr[i])
            {
                i++;
                arr[i] = arr[j];
            }
        }

        return i+1;
    }

};

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 3};

    Solution obj;

    int k = obj.DuplicatedorNot(arr);

    cout << k;

    return 0;
}