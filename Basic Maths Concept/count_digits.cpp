#include<bits/stdc++.h>
using namespace std;

//Time Complexity -> O(log10(n))

//Log base is equivalent to the number 'n' is divided by. In this case it's 10, it could be 2 or 5 or anything

int count(int num)
{
    int tnum = num;
    int cnt = 0;

    while(num != 0)
    {
        tnum = num % 10;
        cnt++;
        num /= 10;
    }

    return cnt;
}

int main()
{
    int num = 33987;

    int n = count(num);

    cout << "No. of digits in " << num << " is " << n;

    return 0;
}

//Another Method

// int count(int num)
// {
//     int cnt = log10(num)+1;
//     return cnt;
// }

