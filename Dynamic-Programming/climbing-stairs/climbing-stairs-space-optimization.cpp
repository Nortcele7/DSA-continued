#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n = 3;

    int curr;
    int prev2=1;
    int prev=1;
    
    for(int i=2; i<=n; i++)
    {
        curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }

    cout<<curr;

}