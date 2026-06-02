#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {1,2,3};

    int n = arr.size();

    int target = 4;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(i==0)
            {
                if(j%arr[i]==0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                int not_take = dp[i-1][j];

                int take = 0;

                if(j>=arr[i])
                {
                    take = dp[i][j-arr[i]];
                }

                dp[i][j] = not_take + take;

            }
        }
    }

    cout<<dp[n-1][target];



}