#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{

    vector<int> weight = {3,2,4};
    vector<int> val = {30, 40, 60};

    int n = weight.size();

    int wt = 6;

    vector<vector<int>> dp(n, vector<int>(wt+1, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=wt; j++)
        {
            if(i==0)
            {
                if(j>=weight[i])
                {
                    dp[i][j] = val[i];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                int not_take = dp[i-1][j];

                int take = INT_MIN;

                if(j>=weight[i])
                {
                    take = val[i]+dp[i-1][j-weight[i]];
                }

                dp[i][j] = max(not_take, take);
            }
        }
    }


    cout<<dp[n-1][wt];
}
