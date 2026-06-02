#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{

    vector<int> arr = {1,2,3};
    int n = arr.size();

    int target = 7;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(i==0)
            {
                if(j%arr[i]==0)
                {
                    dp[i][j] = j/arr[i];
                }
                else
                {
                    dp[i][j] = 1e8;
                }
            }

            else
            {
                int not_take = dp[i-1][j];

                int take = 1e8;

                if(j>=arr[i])
                {
                    take = 1 + dp[i][j-arr[i]];
                }

                dp[i][j] = min(not_take, take);

            }
        }
    }

    cout<<dp[n-1][target];





}