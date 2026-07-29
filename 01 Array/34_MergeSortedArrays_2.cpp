#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC -> O(m+n) + O(m+n)
//SC -> O(m+n)
void bruteForce(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums3;

    int left = 0;
    int right = 0;

    while(left < n && right < m)
    {
        if(nums1[left] <= nums2[right])
        {
            nums3.push_back(nums1[left]);
            left++;
        }
        else
        {
            nums3.push_back(nums2[right]);
            right++;
        }
    }

    while(left < n)
    {
        nums3.push_back(nums1[left]);
        left++;
    }

    while(right < m)
    {
        nums3.push_back(nums2[right]);
        right++;
    }   

    for(int i = 0; i < n+m; i++)
    {
        if(i < n) nums1[i] = nums3[i];

        else nums2[i-n] = nums3[i];        
    }
    
    
}

//Better Approach
//TC -> O(m+n)
//SC -> O(m)
void betterSol(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    vector<int> nums1Copy = nums1;

    int p1 = 0; // for Nums1Copy
    int p2 = 0; //for Nums2
    int k = 0; //for write in Nums1

    while(k < m+n)
    {
        //Case 1: Nums1Copy is exhauted -> take from Nums2
        if(p1 == m)
        {
            if(k < m)
            {
                nums1[k] = nums2[p2++];
            }
            else{
                nums2[k-m] = nums2[p2++];
            }
        }

        //Case 2: Nums2 is exhausted -> take from Nums1Copy
        else if(p2 == n)
        {
            if(k < m)
            {
                nums1[k] = nums1Copy[p1++];
            }
            else
            {
                nums2[k-m] = nums1Copy[p1++];
            }
        }

        //Case 3: both have elements, and arr1Copy[p1] <= arr2[p2]
        else if(nums1Copy[p1] <= nums2[p2])
        {
            if(k < m)
            {
                nums1[k] = nums1Copy[p1++];
            }
            else
            {
                nums2[k-m] = nums1Copy[p1++];
            }
        }

        //Case 4: both have elements, and arr2[p2] < arr1Copy[p1]
        else
        {
            if(k < m)
            {
                nums1[k] = nums2[p2++];
            }
            else
            {
                nums2[k-m] = nums2[p2++];
            }
        }

        k++;        
    }

}

//Optimal Solution 1
//TC -> O()
//SC -> O()
void optimalSol1(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    int left = m-1;
    int right = 0;

    while(left >= 0 && right < n)
    {
        if(nums1[left] >= nums2[right])
        {
            swap(nums1[left--], nums2[right++]);
        }
        else
        {
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

//Optimal Solution 2
//TC -> O((n + m) log(n + m))
//SC -> O(1)
void optimalSol2(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    int len = m+n;

    int gap = (len)/2 + (len%2);

    while (gap > 0) 
    {
        int left = 0;
        int right = left + gap;

        while(right < len)
        {
            //Case 1: Left is in Nums1 and Right is in Nums2
            if(left < m && right >= m)
            {
                if(nums1[left] > nums2[right-m])
                {
                    swap(nums1[left], nums2[right-m]);
                }
            }

            //Case 2: Both in Nums1

            else if(left < m and right < m)
            {
                if(nums1[left] > nums1[right])
                {
                    swap(nums1[left], nums1[right]);
                }
            }

            //Case 3: Both in Nums1
            else
            {
                if(nums2[left-m] > nums2[right-m])
                {
                    swap(nums2[left-m], nums2[right-m]);
                }
            }

            left++;
            right++;
        }

        if(gap == 1) break;

        gap = (gap/2) + (gap%2);
    }
    
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 5, 9, 10};
    vector<int> nums2 = {0, 2, 6, 8, 9};

    optimalSol2(nums1, nums2);

    for(auto it: nums1)
    {
        cout << it << " ";
    }

    cout << endl;
    for(auto it :  nums2)
    {
        cout << it << " ";
    }

    return 0;
}