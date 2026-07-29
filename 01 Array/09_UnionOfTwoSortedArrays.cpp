#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n1log n + n2log n) + O(n1 + n2)
//SC -> O(n1 + n2) + O(n1 + n2)
vector<int> bruteForce(vector<int>& arr1, vector<int>& arr2)
{
    set<int> st;

    for(int i = 0; i < arr1.size(); i++)
    {
        st.insert(arr1[i]);
    }
    for(int i = 0; i < arr2.size(); i++)
    {
        st.insert(arr2[i]);
    }

    vector<int> result;

    for(auto it : st)
    {
        result.emplace_back(it);
    }

    return result;
}

//OPtimal Soln
//TC -> O()
//SC -> O()
vector<int> optimalSol(vector<int>& arr1, vector<int>& arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;

    vector<int> unionArray;

    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j])
        {
            if(unionArray.size() == 0 || unionArray.back() != arr1[i])
            {
                unionArray.emplace_back(arr1[i]);
            }
            i++;
        }

        else
        {
            if(unionArray.size() == 0 || unionArray.back() != arr2[j])
            {
                unionArray.emplace_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < n1)
    {
        if(unionArray.size() == 0 || unionArray.back() != arr1[i])
        {
            unionArray.emplace_back(arr1[i]);
        }
        i++;
    }

    while(j < n2)
    {
        if(unionArray.size() == 0 || unionArray.back() != arr2[j])
        {
            unionArray.emplace_back(arr2[j]);
        }
        j++;
    }

    return unionArray;

}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};

    vector<int> result;
 
    result = optimalSol(arr1, arr2);

    for(auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}