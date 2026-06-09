#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> arr = {2,3,1,1};

    int n=arr.size();

    int target = 4;

    vector<vector<bool>> dp (n, vector<bool>(target+1, false));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(j==0)
            {
                dp[i][j] = true;
            }
            else if(i==0)
            {
                dp[i][j] = (arr[i]==j);
            }
            else
            {
                bool not_take = dp[i-1][j];

                bool take = false;

                if(j>=arr[i])
                {
                    take = dp[i-1][j-arr[i]];
                }

                dp[i][j] = take || not_take;
            }
        }
    }

    cout<<dp[n-1][target];

}