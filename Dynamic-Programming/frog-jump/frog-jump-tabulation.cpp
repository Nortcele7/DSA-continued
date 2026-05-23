#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{


    vector<int> arr = {30, 10, 60, 10, 60, 50};

    int n = arr.size();

    vector<int> dp(n, -1);

    dp[0] = 0;

    int jump1, jump2;

    for(int i=1; i<n; i++)
    {
        jump2 = INT_MAX;

        jump1 = dp[i-1]+abs(arr[i]-arr[i-1]);

        if(i>1)
        {
            jump2 = dp[i-2]+abs(arr[i]-arr[i-2]);
        }

        dp[i] = min(jump1, jump2);
    }

    cout<<dp[n-1];


}