#include<bits/stdc++.h>
using namespace std;

class isSorted
{
    public:
        bool ifSortedORnot(vector<int> &arr)
        {
            int n = arr.size();
            for(int i = 0; i < n-1; i++)
            {
                if(arr[i] <= arr[i+1])
                {

                }
                else return false;
            }

            return true;
        }


        //if array is sorted and rotated it should have only one odp and the last elem <= first elem 
        bool ifSortedAndRotated(vector<int> &arr)
        {
            int n = arr.size();
            int odp = 0; //odp => one decreasing pair counter

            for(int i = 0; i < n; i++)
            {
                if(arr[i] > arr[(i+1) % n] && ++odp > 1) return false;//modulo ensures that when we reach the last element of the array, we can compare it with the first element
            }

            return true;
        }



};

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2, 6};

    isSorted obj1;

    bool ans = obj1.ifSortedAndRotated(arr);

    if(ans == 1)
    {
        cout << "Sorted";
    }
    else cout << "UnSorted";

}