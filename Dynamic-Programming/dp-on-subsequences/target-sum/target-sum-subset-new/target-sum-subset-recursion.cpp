#include<iostream>
#include<vector>
using namespace std;

int subsetSum(vector<int>& arr, int target, vector<vector<int>>& dp)
{

    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(i==0)
            {
                if(j==0 && arr[i]==j)
                {
                    dp[i][j] = 2;
                }

                else if(j==0 || arr[i]==j)
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
                    take = dp[i-1][j-arr[i]];
                }

                dp[i][j] = not_take + take;
            }
        }
    }

    return dp[n-1][target];


}

int main()
{

    vector<int> arr = {1,2,3,1};

    int n = arr.size();

    int target = 3;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }


    if(((sum-target)<0) || ((sum-target)%2!=0))
    {
        return 0;
    }

    else
    {

        int s2 = (sum-target)/2;

        cout<<subsetSum(arr, s2, dp);

    }



}