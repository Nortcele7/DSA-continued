#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& dp_array)
{
    if(n==0||n==1)
    {
        return n;
    }
    else
    {
        if(dp_array[n]!=-1)
        {
            return dp_array[n];
        }
        return dp_array[n] = fib(n-1, dp_array)+fib(n-2, dp_array);
    }
}

int main()
{
    int n = 6;

    vector<int> dp_array(n+1, -1);

    cout<<fib(n, dp_array);





}