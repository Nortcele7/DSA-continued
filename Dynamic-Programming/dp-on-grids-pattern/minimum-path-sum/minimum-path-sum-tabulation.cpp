#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main()
{
    vector<vector<int>> path  = {{5,9,6},{11,5,2}};

    int m=path.size();
    int n=path[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=path[i][j];
            }

            else
            {
                
                int left=INT_MAX, up=INT_MAX;

                if(j>0)
                {
                    left = path[i][j] + dp[i][j-1];
                }

                if(i>0)
                {
                    up = path[i][j] + dp[i-1][j];
                }

                dp[i][j] = min(left, up);

            }

        }
    }

    cout<<dp[m-1][n-1];

}