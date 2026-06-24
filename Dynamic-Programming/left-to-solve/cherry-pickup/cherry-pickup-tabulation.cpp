#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{0,1,-1},{1,0,-1},{1,1,1}};

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                if(arr[i][j]==-1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = arr[i][j];
                }
            }
            else
            {
                if(arr[i][j]==-1)
                {
                    dp[i][j] = -1e8;
                }

                else{
                    int left=-1e8, up=-1e8;
                    if(j>0)
                    {
                        left = arr[i][j] + dp[i][j-1];
                    }

                    if(i>0)
                    {
                        up = arr[i][j] + dp[i-1][j];
                    }

                    dp[i][j] = max(left, up);
                }
            }
        }
    }

    cout<<dp[n-1][n-1];


}