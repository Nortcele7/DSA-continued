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

    vector<int> prev(wt+1, 0);
    vector<int> curr(wt+1, 0);

    // Replace dp[i] by curr and dp[i-1] by prev 
    // Then after j's loop do prev=curr


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=wt; j++)
        {
            if(i==0)
            {
                if(j>=weight[i])
                {
                    curr[j] = val[i];
                }
                else
                {
                    curr[j] = 0;
                }
            }
            else
            {
                int not_take = prev[j];

                int take = INT_MIN;

                if(j>=weight[i])
                {
                    take = val[i]+prev[j-weight[i]];
                }

                curr[j] = max(not_take, take);
            }
        }
        prev=curr;
    }


    cout<<prev[wt];
}
