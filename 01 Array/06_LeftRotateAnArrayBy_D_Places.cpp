#include<bits/stdc++.h>
using namespace std;

//Aproach 1
//TC -> O(n)
//SC -> O(n)
vector<int> bruteForce(vector<int>& arr, int n, int k)
{
    vector<int> temp(n);

    for(int i = 0; i < n; i++)
    {
        temp[i] = arr[(i+k)%n];
    }

    return temp;
}


//Approach 2
//TC -> O(n+k)
//SC -> O(k) : cuz we're creating another array of same size
void appr2(vector<int>& arr,int n, int k)
{    
    k = k % n; // recalculate k for how many times to rotate the ary in case k > n
    //e.g -> if k = 8, then 8%7 -> 1 only one rotation not 8

    vector<int> temp(k);

    //push k elements in temp ary
    for(int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    //shift remaining elements to left
    for(int i = k; i < n; i++)
    {
        arr[i-k] = arr[i];
    }

    //placing back ele from temp to arr
    for(int i = n-k; i < n; i++)
    {
        arr[i] = temp[i - (n-k)];
    }
}


//Aproach 3
//TC -> O(2N)
//SC -> O(1)
class Rotate
{
    private:

        void reverseArray(vector<int>& arr, int strt, int end)
        {
            while (strt < end)
            {
                swap(arr[strt], arr[end]);
                strt++;
                end--;
            }
            
        }

    public:

        void optimalSol(vector<int>& arr, int n, int k)
        {
            k = k%n;
            reverseArray(arr, 0, k-1);
            reverseArray(arr, k, n-1);
            reverseArray(arr, 0, n-1);
        }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3;
    int n = arr.size();

    // vector<int> result;
    Rotate obj;

    obj.optimalSol(arr, n, k);

    for(auto it : arr)
    {
        cout << it << " ";
    }



    return 0;
}