#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(N logN + N)
//SC -> O(1)
int bruteApproach(vector<int> &arr)
{
    sort(arr.begin(), arr.end()); //Sort Array

    int n = arr.size(); //Find aArray Size

    int largest = arr[n-1]; //Create largest var and assign the last value in sorted array

    int slargest; //declare slargest var


    //for loop to find if the Arr[n-2] is not same as largest variable
    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] != largest)
        {
            slargest = arr[i];
            break;
        }
    }

    return slargest;
}

//Better Solution
//TC -> O(N + N) -> O(2N
//SC -> O(1)
int betterSol(vector<int> &arr)
{
    int largest = INT_MIN;
    int n = arr.size();

    //First Pass
    //Run for O(N) to find largest
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    int slargest = INT_MIN;

    //Second Pass
    //Run for another O(N) to find Second Largest
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > slargest && arr[i] != largest)
        {
            slargest = arr[i];
        }
    }

    return slargest;
}

//Optimal Solution
//TC ->
//SC ->
int optimalSol(vector<int> &arr)
{
    int n = arr.size();
    int largest = arr[0];
    //if(arr contains negatives) slargest = INT_MIN
    //else slargest = -1
    int slargest = -1;
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }

        else if(arr[i] > slargest && arr[i] < largest)
        {
            slargest = arr[i];
        }
    }

    return slargest;
}


int main()
{
    vector<int> arr = {1, 2, 4, 7, 7, 5};

    int result;

    result = optimalSol(arr);

    cout << result;

    return 0;
}