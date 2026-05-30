#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{2},{3,4},{6,5,7},{4,1,8,3}};

    int n = arr.size();

    vector<vector<int>> dp(n);

    for(int i=0; i<n; i++)
    {
        dp[i] = vector<int>(i+1, -1);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = arr[i][j];
            }
            else
            {
                int up=INT_MAX, diagonal=INT_MAX;

                if(i>0 && j<=i-1)  // We can go upward only in this condition
                {
                    up = arr[i][j] + dp[i-1][j];
                }

                if(i>0 && j>0)
                {
                    diagonal = arr[i][j] + dp[i-1][j-1];
                }

                dp[i][j] = min(up, diagonal);

            }
        }
    }

    int min_val = INT_MAX;

    for(int j=n-1; j>=0; j--)
    {
        min_val = min(min_val, dp[n-1][j]);
    }

    cout<<min_val;


}