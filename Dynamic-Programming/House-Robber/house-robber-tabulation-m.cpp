#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,1};

    int n = arr.size();

    vector<int> dp(n, -1);

    dp[0] = arr[0];

    for(int i=1; i<n; i++)
    {
        int pick=arr[i];
        if(i>=2)
        {
            pick = arr[i]+dp[i-2];
        }
        int not_pick = 0+dp[i-1];
        dp[i] = max(pick, not_pick);
    }

    cout<<dp[n-1];

}