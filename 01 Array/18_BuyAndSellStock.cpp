#include<bits/stdc++.h>
using namespace std;

//TC -> O(n)
//TC -> O(1)
int func(vector<int>& prices){
    int n = prices.size();

    int bestBuy = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++)
    {
        if(prices[i] > bestBuy)
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }

        bestBuy = min(bestBuy, prices[i]);
    }

    return maxProfit;

}



int main()
{
    vector<int> arr = {2, 4, 1};

    int ans;

    ans = func(arr);

    cout << ans;

    return 0;
}