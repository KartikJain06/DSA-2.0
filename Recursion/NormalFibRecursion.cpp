#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n <= 1) return n;

    return fib(n-1) + fib(n-2);
}

//Memoization Method

int fibFunc(int n, vector<int>& memo)
{
    if(n <= 1)return n;

    if(memo[n] != -1)return memo[n];

    memo[n] = fibFunc(n-1, memo) + fibFunc(n-2, memo);

    return memo[n];
}

int main()
{
    int n = 10; // number given by user to find n fib no.
    vector<int> memo(n+1, -1);
    
    //cout << fib(n); calling the function and printing the result directly

    cout << fibFunc(n, memo);

    return 0;
}