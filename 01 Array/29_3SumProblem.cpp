#include<bits/stdc++.h>
using namespace std;

struct VectorHash{
    size_t operator()(const vector<int>& v) const
    {
        size_t hash_val = v.size();

        for(int i : v)
        {
            hash_val ^= hash<int>()(i) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
        }

        return hash_val;
    }
};

//Brute Force Approach
//TC -> O(n^3 log (no. of unique triplets))
//SC -> O(2 * no. of unique triplets)
vector<vector<int>> bruteForce(vector<int>& nums)
{
    set<vector<int>> st;
    for(int i = 0; i < nums.size(); i++)
    {
        int sum = 0;


        for(int j = i+1; j < nums.size(); j++)
        {
            for(int k = j+1; k < nums.size(); k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                } 
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

//Better Sol
//TC -> O(n^2 log(no. of unique triplets))
//SC -> O(N) + (O(no. of unique triplets)*2)
//Hashing Used Here
vector<vector<int>> betterSol(vector<int>& nums)
{
    unordered_set<vector<int>, VectorHash> st;
    for(int i = 0; i < nums.size(); i++)
    {
        unordered_set<int> hashset;
        for(int j = i+1; j < nums.size(); j++)
        {
            int third  = -(nums[i] + nums[j]);

            if(hashset.find(third) != hashset.end())
            {
                vector<int> temp{nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}


//Optimal Sol
//TC -> O(n log n) + O(n^2)
//SC -> O(no. of unique triplets)
vector<vector<int>> optimalSol(vector<int>& nums)
{
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = nums.size()-1;

        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};   
                ans.emplace_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }

    return ans;
}

//Optimal Sol that prevents modification of array
//TC -> O(n^2 log n)
//SC -> O(n)
vector<vector<int>> optimalSol2(vector<int>& nums)
{
    set<vector<int>> res;
    unordered_set<int> dups;
    unordered_map<int, int> seen;

    for(int i = 0; i < nums.size(); i++)
    {
        if(dups.insert(nums[i]).second)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                int complement = -(nums[i] + nums[j]);

                auto it = seen.find(complement);

                if(it != end(seen) && it->second == i)
                {
                    vector<int> temp = {nums[i], nums[j], complement};
                    sort(begin(temp), end(temp));
                    res.insert(temp);
                }

                seen[nums[j]] = i;
            }
        }
    }

    return vector<vector<int>>(res.begin(), res.end());
}


//For Interview purpose focus on two-pointer approach, but it'll modify the array elements
//If interviewer asks to give output without changing then the optimalSol2() is good

int main()
{
    vector<int> nums = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};

    vector<vector<int>> ans;

    ans = optimalSol(nums);

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