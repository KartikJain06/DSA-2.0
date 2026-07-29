#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(n^4 log(no. of unique quadruplets))
//SC -> O(no.of unique quadruplets)
vector<vector<int>> bruteForce(vector<int>& arr, int target)
{
    set<vector<int>> res;

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i+1; j < arr.size(); j++)
        {
            for(int k = j+1; k < arr.size(); k++)
            {
                for(int l = k+1; l < arr.size(); l++)
                {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(begin(temp), end(temp));
                        res.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(res.begin(), res.end());
}

//Better Sol
//TC -> O(n^3 logM) -> M = no. of elems in hashSet
//SC -> O(2*no. of quads) + O(n) -> N -> atmost N elements in hashSet
vector<vector<int>> betterSol(vector<int>& arr, int target)
{
    set<vector<int>> st;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i+1; j < arr.size(); j++)
        {
            set<long long> hashset;
            for(int k = j+1; k < arr.size(); k++)
            {
                long long fourth = target - (arr[i] + arr[j] + arr[k]);

                if(hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(begin(temp), end(temp));
                    st.insert(temp);
                }

                hashset.insert(arr[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

//Optimal Sol : will use two pointer approach
//TC -> O(n^3)
//SC -> O(no. of quadruplets)
vector<vector<int>> optimalSol(vector<int>& arr, int target)
{
    sort(begin(arr), end(arr));

    vector<vector<int>> ans;

    for(int i = 0; i < arr.size(); i++)
    {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j < arr.size(); j++)
        {
            if(j > i+1 && arr[j] == arr[j-1]) continue;

            int k = j+1;
            int l = arr.size()-1;

            while(k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];

                if(sum == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.emplace_back(temp);
                    k++;
                    l--;

                    while(k < l && arr[k] == arr[k-1]) k++; 
                    while(k < l && arr[l] == arr[l+1]) l--; 
                }
                else if(sum < target) k++;
                else l--;             
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 5;

    vector<vector<int>> ans;

    ans = optimalSol(arr, target);

    for(auto it : ans)
    {
        for(auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}