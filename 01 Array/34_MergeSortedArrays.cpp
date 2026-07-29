#include<bits/stdc++.h>
using namespace std;

//This question is when Nums1 has extra space means m+n, and we've to transfer elements from nums2 to nums1, not have to modify nums1 and nums2 based on sorted elements

//Brute Force Approach
//TC -> O((m+n)log(m+n))
//SC -> O(1)
void bruteForce(vector<int>& num1, int m, vector<int>& num2, int n)
{

    if(n == 0) return; //If Num2 is empty, there is no need to go further, as there is nothing to merge so simply return and array Num1 will be the final


    //copy the elems from Num2 to Num1, where 0 lies iin the end, means ignored space
    for(int i = 0; i < n; i++)
    {
        num1[i+m] = num2[i];
    }

    //finally all elemenst from Num2 is in Num1, so sort it out
    sort(num1.begin(), num1.end());
}

//Better Solution
//TC -> O(m+n)
//SC -> O(m)
void betterSol(vector<int>& num1, int m, vector<int>& num2, int n)
{
    //Will create a copy of array Num1
    vector<int> num1Copy(m);

    for(int i = 0; i < m; i++)
    {
        num1Copy[i] = num1[i];
    }

    //Read pointers for num1Copy and num2
    int p1 = 0;
    int p2 = 0;

    for(int p = 0; p < m+n; ++p)
    {
        if(p2 >= n || (p1 < m && num1Copy[p1] < num2[p2]))
        {
            num1[p] = num1Copy[p1++];
        }
        else
        {
            num1[p] = num2[p2++];
        }
    }


}


//Optimal Solution
//TC -> O(m+n)
//SC -> O(1)
void optimalSol(vector<int>& num1, int m, vector<int>& num2, int n)
{
    int p1 = m-1;
    int p2 = n-1;

    for(int p = m+n-1; p >= 0; p--)
    {
        if(p2 < 0) break;

        if(p1 >= 0 && num1[p1] > num2[p2])
        {
            num1[p] = num1[p1--];
        }
        else
        {
            num1[p] = num2[p2--];
        }
    }
}

int main()
{
    vector<int> num1 = {3, 3, 3, 0, 0, 0};
    vector<int> num2 = {2, 2, 2};
    int m = 3;
    int n = 3;

    optimalSol(num1, m, num2, n);

    for(auto it : num1)
    {
        cout << it << " ";
    }

    return 0;
}