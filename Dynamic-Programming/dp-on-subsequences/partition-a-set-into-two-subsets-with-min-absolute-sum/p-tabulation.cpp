#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void subsetSum(vector<int>& arr, int target, vector<vector<bool>>& dp)
{

    int n=arr.size();

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

}

int main()
{

    vector<int> arr = {3,2,7};

    int n = arr.size();

    int sum=0;

    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }

    vector<vector<bool>> dp (n, vector<bool>(sum+1, false));

    subsetSum(arr, sum, dp);

    // Valid S1s

    int min_val = INT_MAX;

    for(int s1=0; s1<=sum; s1++)
    {
        if(dp[n-1][s1])
        {
            int s2 = sum-s1;
            int abs_diff = abs(s1-s2);
            min_val = min(min_val, abs_diff);
        }
    }

    cout<<min_val;


}