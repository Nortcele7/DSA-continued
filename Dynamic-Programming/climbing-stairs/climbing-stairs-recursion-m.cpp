#include<iostream>
using namespace std;

int climbStairs(int n)
{

    
    if(n==0)
    {
        return 1;
    }

    if(n==1)
    {
        return 1;
    }

    int jump1, jump2;

    jump1 = climbStairs(n-1);
    jump2 = climbStairs(n-2);

    return jump1+jump2;


}

int main()
{
    int n=3;
    cout<< climbStairs(n);
}