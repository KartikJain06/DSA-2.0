#include<bits/stdc++.h>
using namespace std;

//Count Sort Algo to sort the array in O(n)
vector<int> CountSort(vector<int> &nums)
{
    //Find the max_elem in array
    auto max = *max_element(nums.begin(), nums.end());

    //Create array of size max_elem + 1
    vector<int> arr(max+1, 0);

    //Store the frequency of elements in this frequency array
    for(auto it : nums)
    {
        arr[it]++;
    }

    //Clear the main array
    nums.clear();

    int n = arr.size();

    //Rebuild the main array using frequency array
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

int maxFrequency(vector<int> &nums, int k)
{
    vector<int> num = CountSort(nums);

        //Initiate total to store sum, start & end pointer to iterate through array, and a variable to store max_frequency

        long long total = 0;
        int start = 0;
        int max_freq = 0;
        int size = num.size();

        //Here using Sliding Window Algo

        for(int end = 0; end < size; end++)
        {
            //add the end pointer elem to the total sum
            total += num[end];

            //Check if the window is valid or not, if not then increment the start pointer after subtracting the leftmost element on which start pointer was previously pointing
            if((long long)num[end]*(end - start + 1) - total > k)
            {
                total -= num[start];
                start++;
            }

            //Store the max frequency by the difference of start & end pointer
            max_freq = max(max_freq, end - start + 1);
        }

        return max_freq;
}
int main()
{
    vector<int> nums = {1, 2, 4, 13};
    int k = 5;

    int output = maxFrequency(nums, k);

    cout << output;

    return 0;
}