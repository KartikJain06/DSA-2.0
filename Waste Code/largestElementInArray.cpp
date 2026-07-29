#include<bits/stdc++.h>
using namespace std;

int largestEle(vector<int> &arr)
{
    int max = arr[0];

    for(int i = 0; i < arr.size(); i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

int SeclargestEle(vector<int> &arr, int n)
{
    if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                

}

int main()
{   
    vector<int> arr = {1, 2, 5, 7, 3, 91};
    int n = arr.size();

    cout << SeclargestEle(arr, n);

    return 0;
}