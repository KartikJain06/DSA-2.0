#include<bits/stdc++.h>
using namespace std;

bool checkArray(vector<int> &a)
{
    int n = a.size();
    int rotates = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > a[(i+1)%n] && ++rotates > 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> a = {2, 3, 4, 5, 1};

    bool result;
    result = checkArray(a); 

    cout << ((result) ? "true" : "false");

    return 0;
}