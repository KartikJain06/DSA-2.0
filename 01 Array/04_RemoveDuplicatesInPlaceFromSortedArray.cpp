#include<bits/stdc++.h>
using namespace std;

//Brute Force approach
//TC -> O(N log N + N);
//SC -> O(N);
int bruteForce(vector<int>& a)
{
    int n = a.size();
    
    //Create Set and iterate the array and store elements in set
    //Set only stores unique elements
    set<int> st;

    for(int i = 0; i < n; i++)
    {
        st.insert(a[i]); //Inserting in set takes "log N" so
        //whole loop TC ->O(N logN) 
    }

    //Iterate the set and store every elements of set in array from starting
    int ind = 0;
    //TC -> O(N)
    for(auto it: st)
    {
        a[ind] = it;
        ind++;
    }

    return ind;
}

//OPtimal Solution
//TC -> O(N)
//SC -> O(1)
int optimalSol(vector<int>& arr)
{
    int n = arr.size();

    int i = 0;
    for(int j = 1; j < n; j++)
    {
        if(arr[i] != arr[j])
        {
            arr[i+1] = arr[j];
            i++;
        }
    }

    return i+1;
}


int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 3};

    int k;
    k = optimalSol(arr);

    cout << k << endl;
    for(int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}