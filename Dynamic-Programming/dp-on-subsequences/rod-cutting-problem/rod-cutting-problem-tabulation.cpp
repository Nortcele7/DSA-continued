#include<iostream>
#include<vector>

using namespace std;

int main()
{

    vector<int> price = {2,5,7,8,10};

    int n = price.size();

    vector<vector<int>>dp(n, vector<int>(n+1, -1));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
            {
                dp[i][j] = j*price[i];
            }
            
            else
            {
                int not_take = dp[i-1][j];

                int take = 0;

                if(j>=(i+1))
                {
                    take = price[i] + dp[i][j-(i+1)];
                }

                dp[i][j] = max(not_take, take);
            }
 
        }
    }

    cout<<dp[n-1][n];

}