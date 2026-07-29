#include<bits/stdc++.h>
using namespace std;

int findMaxOnes(vector<int>& arr)
{
    int ans = 0;
    int cnt = 0;
    for(auto it : arr)
    {
        if(it == 1)
        cnt++;
        else 
        cnt = 0;

        ans = max(ans, cnt);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 0, 0, 1, 0, 1, 1, 1, 1};

    int ans;

    ans = findMaxOnes(arr);

    cout << ans;


    return 0;
}