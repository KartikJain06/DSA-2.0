#include<bits/stdc++.h>
using namespace std;

//Brute Force 
//TC -> O(n)
//SC -> O(1)
int bruteForce(vector<int>& arr)
{
    int n = arr.size();
    int ans;
    int cnt = 0;

    if(n == 1) return arr[0];

    for(int i = 0; i < n; i++)
    {
        if(i == 0){
            if(arr[i] != arr[i+1]) return arr[i];
        }
        else if(i == n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }
        else{
            if(arr[i-1] != arr[i] and arr[i+1] != arr[i]){
                return arr[i];
            }
        }
    }

}

int main()
{
    vector<int> arr = {1,1,2,3,3,4,4,6,6,8,8};

    cout << bruteForce(arr);

    return 0;
}