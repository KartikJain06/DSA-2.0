#include<bits/stdc++.h>
using namespace std;

class MoveZeros
{
    public:

        //Aproach 1 : brute Force
        //TC -> O(2n)
        //SC -> O(n);
        void bruteForce(vector<int>& nums)
        {
            vector<int> temp;
            int n = nums.size();

            for(auto it : nums)
            {
                if(it != 0)
                {
                    temp.emplace_back(it);
                }
            }

            int i = 0;
            for(auto it: temp)
            {
                nums[i] = it;
                i++;
            }

            int nze = temp.size();

            for(int i = nze; i < n; i++)
            {
                nums[i] = 0;
            }
        }

        //Approach 2 : Optimal Sol 1
        //TC -> O(n)
        //SC -> O(1)
        void optimalSol1(vector<int>& nums)
        {
            int n = nums.size();
            
            int j = -1;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] == 0)
                j = i;
                break;
            }

            for(int i = j+1; i < n; i++)
            {
                if(nums[i] != 0)
                {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
        }

        //Approach 3 : OPtimal Sol 2
        //TC -> O(n)
        //SC -> O(1)
        void optimalSol2(vector<int>& nums)
        {
            int j = 0;

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i]) {
                    nums[j++] = nums[i];
                }
            }

            for(int i = j; j < nums.size(); j++) {
                nums[j] = 0;
            }
        }

        //Approach 4 : 
        //TC -> O(n) 
        //SC -> O(1)
        void optimalSol3(vector<int>& nums)
        {
            for(int l = 0, r = 0; r < nums.size(); r++)
            {
                if(nums[r])
                {
                    swap(nums[r], nums[l++]);
                }
            }
        } 

};

int main()
{
    vector<int> nums = {0, 0, 0, 0, 1};

    MoveZeros obj;

    obj.optimalSol1(nums);
    
    for(auto it : nums)
    {
        cout << it << " ";
    }

    return 0;
}