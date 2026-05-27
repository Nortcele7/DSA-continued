#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{

    vector<vector<int>> arr = {{2,1,3}, {6,5,4}, {7,8,9}};

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0)
            {
                dp[i][j] = arr[i][j];
            }

            else
            {
                int up=INT_MIN, leftd=INT_MIN, rightd=INT_MIN;

                if(i>0)
                {
                    up = arr[i][j] + dp[i-1][j];
                }

                if(i>0 && j>0)
                {
                    leftd = arr[i][j] + dp[i-1][j-1];
                }

                if(i>0 && j<m-1)
                {
                    rightd = arr[i][j] + dp[i-1][j+1];
                }

                dp[i][j] = max(up, max(leftd, rightd));

            }

        }
    }

    int max_val = INT_MIN;

    for(int j=m-1; j>=0; j--)
    {
        max_val = max(max_val, dp[n-1][j]);
    }

    cout<<max_val;

}