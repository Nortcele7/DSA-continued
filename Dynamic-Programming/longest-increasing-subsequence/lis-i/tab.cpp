#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};

    int n = arr.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    int len;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i-1; j>=-1; j--)
        {
            len = 0 + dp[i+1][j+1];

            if(j==-1 || arr[i]>arr[j])
            {
                len = max(len, 1+dp[i+1][i+1]);
            }
            dp[i][j+1] = len;
        }
    }

    cout<<dp[0][0]<<endl;

    vector<int> lis;

    int i = 0;
    int prev = -1;

    while(i < n)
    {
        int notTake = dp[i+1][prev+1];

        int take = INT_MIN;

        if(prev == -1 || arr[i] > arr[prev])
            take = 1 + dp[i+1][i+1];

        if(take >= notTake)
        {
            lis.push_back(arr[i]);
            prev = i;
        }

        i++;
    }

    for(int x : lis)
        cout << x << " ";
}