#include<bits/stdc++.h>
using namespace std;

vector<int> CountSort(vector<int> &nums)
{
    auto max = *max_element(nums.begin(), nums.end());

    vector<int> arr(max+1, 0);


    for(auto it : nums)
    {
        arr[it]++;
    }

    nums.clear();

    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int times = arr[i];

        while (times--)
        {
            nums.emplace_back(i);
        }
        
    }

    return nums;
}

int main()
{
    vector<int> nums = {2, 3, 2, 1, 5, 3, 1, 5, 4};
    
    
    CountSort(nums);

    for(auto it : nums)
    {
        cout << it << " ";
    }
    

    return 0;
}