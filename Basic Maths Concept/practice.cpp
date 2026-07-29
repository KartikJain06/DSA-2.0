#include<bits/stdc++.h>
using namespace std;

int frec(int n)
{
    if(n <= 1)return n;

    return frec(n-1) + frec(n-2);
}   

int main()
{
    int n;

    cin >> n;

    cout << frec(n);

    unordered_map<double, int> ump;


    
    return 0;
}